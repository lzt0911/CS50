import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd
from datetime import datetime

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    table_exist = db.execute(
        "SELECT name FROM sqlite_master WHERE type='table' AND name=?", 'stock')
    if not table_exist:
        return render_template("index.html", symbol=[], price=[], shares=[], total=[], cash=10000, remain=10000)
    stocks = db.execute("SELECT * FROM stock WHERE userid = ?", session["user_id"])
    symbols = []
    prices = []
    shares = []
    total = []
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
    sum_money = 0
    if stocks:
        for stock in stocks:
            symbols.append(stock["symbol"])
            price = lookup(stock["symbol"])["price"]
            prices.append(price)
            share = stock["shares"]
            shares.append(share)
            total.append(price * share)
            sum_money += price * share
        sum_money += cash
        return render_template("index.html", symbol=symbols, price=prices, shares=shares, total=total, cash=cash, remain=sum_money)
    else:
        return render_template("index.html", symbol=[], price=[], shares=[], total=[], cash=10000, remain=10000)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("symbol is empty")
        list = lookup(symbol)
        if not list:
            return apology("Can't find symbol")
        shares = request.form.get("shares")
        if not shares.isdigit() or not shares or int(shares) <= 0:
            return apology("shares shoulb be positive")
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
        if cash < list["price"] * int(shares):
            return apology("Don't have enough crash")
        table_exist = db.execute(
            "SELECT name FROM sqlite_master WHERE type='table' AND name=?", 'history')
        if not table_exist:
            db.execute("""
                       CREATE TABLE history (
                            time DATE NOT NULL,
                            userid INTEGER NOT NULL,
                            type TEXT NOT NULL,
                            symbol TEXT NOT NULL,
                            price FLOAT NOT NULL,
                            shares INTEGER NOT NULL,
                            FOREIGN KEY (userid) REFERENCES users(id),
                            CHECK (type IN ('buy', 'sell'))
                       )
                    """)
        db.execute("INSERT INTO history (time, userid, type, symbol, price, shares) VALUES (?, ?, ?, ?, ?, ?)",
                   datetime.now(), session["user_id"], 'buy', list["symbol"], list["price"], shares)
        table_exist = db.execute(
            "SELECT name FROM sqlite_master WHERE type='table' AND name=?", 'stock')
        if not table_exist:
            db.execute("""
                       CREATE TABLE stock (
                            userid INTEGER NOT NULL,
                            symbol TEXT NOT NULL,
                            price FLOAT NOT NULL,
                            shares INTEGER NOT NULL,
                            FOREIGN KEY (userid) REFERENCES users(id)
                       )
                    """)
        row = db.execute("SELECT * FROM stock WHERE symbol = ? AND userid = ?",
                         list["symbol"], session["user_id"])
        if not row:
            db.execute("INSERT INTO stock (userid, symbol, price, shares) VALUES (?, ?, ?, ?)",
                       session["user_id"], list["symbol"], list["price"], int(shares))
        else:
            db.execute("UPDATE stock SET shares = ? WHERE symbol = ? AND userid = ?",
                       (row[0]["shares"] + int(shares)), list["symbol"], session["user_id"])
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash -
                   list["price"] * int(shares), session["user_id"])
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    table_exist = db.execute(
        "SELECT name FROM sqlite_master WHERE type='table' AND name=?", 'history')
    if not table_exist:
        return render_template("history.html")
    history = db.execute("SELECT * FROM history WHERE userid = ?", session["user_id"])
    if not history:
        return render_template("history.html")
    return render_template("history.html", history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("Empty symbol")
        quote = lookup(symbol)
        if not quote:
            return apology("Can't find symbol")
        return render_template("quoted.html", quote=quote)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
       # 获取username, 判断是否为空或已存在
        username = request.form.get("username")
        if not username:
            return apology("username is empty")
       # 获取password和confirmation, 判断是否为空后两者不匹配
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        if not password:
            return apology("password is empty!")
        if not confirmation:
            return apology("confirmation is empty！")
        if password != confirmation:
            return apology("confirmation is not equal to password！")
        # hash password
        hash_password = generate_password_hash(password)
       # insert into db
        try:
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash_password)
        except ValueError:
            return apology("Repeated username!")
        return redirect("/")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "GET":
        table_exist = db.execute(
            "SELECT name FROM sqlite_master WHERE type='table' AND name=?", 'stock')
        if not table_exist:
            return render_template("sell.html", symbols=[])
        symbol = db.execute("SELECT symbol FROM stock WHERE userid = ?", session["user_id"])
        if not symbol:
            return render_template("sell.html", symbols=[])
        return render_template("sell.html", symbols=symbol)
    else:
        symbol = request.form.get('symbol')
        if not symbol:
            return apology("Empty symbol!")
        list = lookup(symbol)
        shares = int(request.form.get('shares'))
        if not shares:
            return apology("Empty shares")
        table_exist = db.execute(
            "SELECT name FROM sqlite_master WHERE type='table' AND name=?", 'stock')
        if not table_exist:
            return apology("hasn't buy stocks yet")
        row = db.execute("SELECT * FROM stock WHERE userid = ?", session["user_id"])
        if not row:
            return apology("hasn't buy stocks yet")
        cur_shares = db.execute(
            "SELECT shares FROM stock WHERE symbol = ? AND userid = ?", symbol, session["user_id"])
        if not cur_shares:
            return apology("hasn't buy stocks yet")
        if shares > int(cur_shares[0]["shares"]):
            return apology("doesn't have enough stock")
        if shares < int(cur_shares[0]["shares"]):
            db.execute("UPDATE stock SET shares = ? WHERE symbol = ? AND userid = ?",
                       int(cur_shares[0]["shares"]) - shares, symbol, session["user_id"])
        else:
            db.execute("DELETE FROM stock WHERE symbol = ? AND userid = ?",
                       symbol, session["user_id"])
        db.execute("INSERT INTO history (time, userid, type, symbol, price, shares) VALUES (?, ?, ?, ?, ?, ?)",
                   datetime.now(), session["user_id"], 'sell', symbol, list["price"], shares)
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
        cash += shares * list["price"]
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"])
        return redirect("/")
