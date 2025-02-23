import csv
from cs50 import SQL

db = SQL("sqlite:///roster.db")

with open('students.csv') as file:
    reader = csv.DictReader(file)
    for row in reader:
        if db.execute("SELECT * FROM students_new WHERE name = ?", row["student_name"]) == []:
            db.execute("INSERT INTO students_new (name) VALUES (?)", row["student_name"])
        if db.execute("SELECT * FROM houses WHERE name = ? AND head = ?", row["house"], row["head"]) == []:
            db.execute("INSERT INTO houses (name, head) VALUES (?, ?)", row["house"], row["head"])
        student_id = db.execute("SELECT id FROM students_new WHERE name = ?", row["student_name"])[0]["id"]
        house_id = db.execute("SELECT id FROM houses WHERE name = ?", row["house"])[0]["id"]
        db.execute("INSERT INTO assignment (student_id, house_id) VALUES (?, ?)", student_id, house_id)
