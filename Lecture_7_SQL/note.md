# Lecture 7
## Flat-File Database(平面文件数据库)
* csv(comma-seperated file)
* If you look at a csv file, you’ll notice that the file is flat in that all of our data is stored in a single table represented by a text file. We call this form of data a flat-file database.
```python
# Prints all favorites in CSV using csv.reader

import csv

# Open CSV file
# open默认权限为只读权限
with open("favorites.csv", "r") as file:

    # Create reader
    reader = csv.reader(file)

    # Skip header row
    next(reader)

    # Iterate over CSV file, printing each favorite
    for row in reader:
        print(row[1])
```
```python
# Prints all favorites in CSV using csv.DictReader

import csv

# Open CSV file
with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Iterate over CSV file, printing each favorite
    for row in reader:
        print(row["language"])
```
```python
# Counts favorites using variables

import csv

# 法一
# Open CSV file
with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Counts
    scratch, c, python = 0, 0, 0

    # Iterate over CSV file, counting favorites
    for row in reader:
        favorite = row["language"]
        if favorite == "Scratch":
            scratch += 1
        elif favorite == "C":
            c += 1
        elif favorite == "Python":
            python += 1

    # Print counts
    print(f"Scratch: {scratch}")
    print(f"C: {c}")
    print(f"Python: {python}")

# 法二
# Open CSV file
with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Counts
    counts = {}

    # Iterate over CSV file, counting favorites
    for row in reader:
        favorite = row["language"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

    # Print counts
    for favorite in counts:
        print(f"{favorite}: {counts[favorite]}")

    # 将key按字母序排序输出
    for favorite in sorted(counts):
        print(f"{favorite}: {counts[favorite]}")

    # 将value按降序输出
    # The key argument allows you to tell Python the method you wish to use to sort items. 
    # In this case counts.get is used to sort by the values. 
    # reverse=True tells sorted to sort from largest to smallest.
    for favorite in sorted(counts, key=counts.get, reverse=True):
        print(f"{favorite}: {counts[favorite]}")

# 法三
from collections import Counter

# Open CSV file
with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Counts
    counts = Counter()

    # Iterate over CSV file, counting favorites
    for row in reader:
        favorite = row["language"]
        counts[favorite] += 1

# Print counts
for favorite, count in counts.most_common():
    print(f"{favorite}: {count}")
```
## Relational Databases
* Relational databases store data in rows and columns in structures called tables.
* Database management system: software via which you can interact with database, such as: MySQL、Oracle、PostgreSQL、SQLite.
* database design principles:
  * create one table for each entity(实体) in your dataset.
  * all tables should have a primary key.
  * the information in the table should depends on the primary key only.
* SQL(structured query language) allows for four types of commands
  ```
  Create
  Read
  Update
  Delete
  ```
```sql
-- create a SQL database
sqlite3 favorites.db

-- put sqlite3 into csv mode
.mode csv

-- import our data from our csv file
-- .import [csv file name] [table name]
.import favorites.csv favorites

-- see the structure of the database
.schema
-- .schema 后面加table可显示具体某个table的结构

-- 可显示database中有哪些表
.tables

CREATE TABLE table_name (
    column0 TYPE,
    column1 TYPE,
    PRIMARY KEY(column0)
);

CREATE TABLE books (
    id INTEGER,
    title TEXT,
    published NUMERIC,
    rating INTEGER,
    PRIMARY KEY(id)
);

CREATE authored (
    author_id INTEGER,
    book_id INTEGER,
    PRIMARY KEY(author_id, book_id),
    FOREIGN KEY(author_id) REFERENCES authors(id),
    FOREIGN KEY(book_id) REFERENCES books(id)
);

-- read items from a table
-- SELECT columns FROM table;
-- 显示table的全部内容
SELECT * FROM favorites; 
SELECT language FROM favorites;
-- 显示language列的十个数据
SELECT language FROM favorites LIMIT 10; 

-- SQL supports many commands to access data
AVG
COUNT
DISTINCT
LOWER
MAX
MIN
UPPER

-- table中有多少行数据
SELECT COUNT(*) FROM favorites;

-- language下不同的数据
SELECT DISTINCT(language) FROM favorites;
SELECT COUNT(DISTINCT(language)) FROM favorites;

-- SQL offers additional commands we can utilize in our queries
WHERE       -- adding a Boolean expression to filter our data
LIKE        -- filtering responses more loosely
ORDER BY    -- ordering responses
LIMIT       -- limiting the number of responses
GROUP BY    -- grouping responses together

COUNT(column)
AVG(column)
ROUND(AVG(column), 2) -- 精确到小数点后2位

SELECT COUNT(*) FROM favorites WHERE language = 'C';
SELECT COUNT(*) FROM favorites WHERE language = 'C' AND problem = 'Hello, World';
SELECT language, COUNT(*) FROM favorites GROUP BY language;
-- 升序排列
SELECT language, COUNT(*) FROM favorites GROUP BY language ORDER BY COUNT(*) ASC;
-- 降序排列
SELECT language, COUNT(*) FROM favorites GROUP BY language ORDER BY COUNT(*) DESC;
-- 多个排序条件
ORDER BY XXX ASC, XXX DESC
-- 给COUNT(*)起别名，方便后续输入
SELECT language, COUNT(*) AS n FROM favorites GROUP BY language ORDER BY n DESC;

-- 查找是否有某个名字的table
SELECT name FROM sqlite_master WHERE type='table' AND name=?
-- INSERT INTO table (column...) VALUES(value, ...);
-- 插入language=SQL, problem=Fiftyville的数据，未指定的字段为NULL
INSERT INTO favorites (language, problem) VALUES ('SQL', 'Fiftyville');

DELETE FROM favorites WHERE Timestamp IS NULL;

-- 将所有数据都设置为SQL, Fiftyville
UPDATE favorites SET language = 'SQL', problem = 'Fiftyville';

-- quit
.quit

-- 运行写在*.sql里的语句
.read *.sql
```
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_7_SQL/images/image.png?raw=true)
## Shows
* 例：电视节目与明星对应表
  * We could separate our database into multiple sheets.
  * On the people sheet, each person could have a unique id. 
  * On the shows sheet, each show could have a unique id too. 
  * On a third sheet called stars we could relate how each show has people for each show by having a show_id and person_id. 
  * While this is an improvement, this is not an ideal database.
* IMDb offers a database of people, shows, writers, stars, genres, and ratings. Each of these tables is related to one another as follows:
  ![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_7_SQL/images/image-1.png?raw=true)
  * show_id exists in all of the tables. In the shows table, it is simply called id. This common field between all the fields is called a key. 
  * Primary keys are used to identify a unique record in a table. (自动增加)
  * Foreign keys are used to build relationships between tables by pointing to the primary key in another table.
  ![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_7_SQL/images/image-2.png?raw=true)
* In sqlite, we have five datatypes, including:
  ```
  BLOB       -- binary large objects that are groups of ones and zeros
  INTEGER    -- an integer
  NUMERIC    -- for numbers that are formatted specially like dates
  REAL       -- like a float
  TEXT       -- for strings and the like
  ```
* Additionally, columns can be set to add special constraints:
  ```
  NOT NULL
  UNIQUE
  ```
```sql
SELECT title FROM shows WHERE id IN (
    SELECT show_id FROM ratings WHERE rating >= 6.0 LIMIT 10
)
```
## JOINS
* JOIN只会合并重叠部分
```sql
-- one-to-one relationship
SELECT * FROM shows JOIN ratings on shows.id = ratings.show_id WHERE rating >= 6.0 LIMIT 10;
```
```sql
-- one-to-many relationship
SELECT * FROM shows JOIN genres ON shows.id = genres.show_id WHERE id = 63881;
```
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_7_SQL/images/image-3.png?raw=true)
```sql
-- many-to-many relationship
SELECT name FROM people WHERE id IN (
  SELECT person_id FROM stars WHERE show_id = (
    SELECT id FROM shows WHERE title = 'The Office' AND year = 2005
  )
);

SELECT title from shows WHERE id IN (
  SELECT show_id FROM stars WHERE person_id = (
    SELECT id FROM people WHERE name = 'Steve Carell'
  )
);

SELECT title FROM shows
  JOIN stars ON shows.id = stars.show_id
  Join people ON stars.person_id = people.id
  WHERE name = 'Steve Carell';

SELECT title FROM shows, stars, people
  WHERE shows.id = stars.show_id
  AND people.id = stars.person_id
  AND name = 'Steve Carell';
```
```sql
SELECT title FROM movies
    JOIN stars AS s1 ON movies.id = s1.movie_id
    JOIN people AS p1 ON s1.person_id = p1.id
    JOIN stars AS s2 ON movies.id = s2.movie_id
    JOIN people AS p2 ON s2.person_id = p2.id
    WHERE p1.name = 'Bradley Cooper' AND p2.name = 'Jennifer Lawrence';
```
```sql
-- The wildcard(通配符) % operator can be used to find all people whose names start with Steve C
SELECT * FROM people WHERE name LIKE 'Steve C%'
```
## Indexes
* Indexes can be utilized to speed up our queries.
* We can track the speed of our queries by executing .timer on in sqlite3.
```sql
-- create an index called title_index on column title.
-- This will create a data structure called a B Tree, a data structure that looks similar to a binary tree. 
-- However, unlike a binary tree, there can be more than two child nodes.

CREATE INDEX title_index on shows (title);
```
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_7_SQL/images/image-4.png?raw=true)
## Using SQL in Python
```python
# Searches database popularity of a problem

import csv

from cs50 import SQL

# Open database
db = SQL("sqlite:///favorites.db")

# Prompt user for favorite
favorite = input("Favorite: ")

# Search for title
# rows is returned as a list of dictionaries
rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem LIKE ?", favorite)

# Get first (and only) row
row = rows[0]

# Print popularity
print(row["n"])
```
## Race Conditions
```sql
-- 获取点赞数并+1
rows = db.execute("SELECT likes FROM posts WHERE id = ?", id)
likes = rows[0]["likes"]
db.execute("UPDATE posts SET likes = ? WHERE id = ?", likes + 1, id)

-- 避免数据竞争
db.execute("BEGIN TRANSACTION")
rows = db.execute("SELECT likes FROM posts WHERE id = ?", id)
likes = rows[0]["likes"]
db.execute("UPDATE posts SET likes = ? WHERE id = ?", likes + 1, id)
db.execute("COMMIT")
```
## SQL Injection Attacks
* SQL中的注释：--
```sql
-- safe
rows = db.execute("SELECT * FROM users WHERE username = ? AND password = ?", username, password)

-- dangerous
rows = db.execute(f"SELECT * FROM users WHERE username = '{username}' AND password = '{password}'")
-- 若用户输入malan@harvard.edu'--, --后面的都将被注释掉
rows = db.execute(f"SELECT * FROM users WHERE username = 'malan@harvard.edu'--' AND password = '{password}'")
-- 等效于
rows = db.execute(f"SELECT * FROM users WHERE username = 'malan@harvard.edu'")

```
## Datatype in SQL 
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_7_SQL/images/image-5.png?raw=true)
* INT、SMALLINT、TINUINT、MEDIUMINT、BIGINT——整数
* DECIMAL、FLOAT——浮点数
* DATE、TIME、DATETIME、TIMESTAMP——日期和时间戳
* GEOMETRY、LINESTRING——绘图
* TEXT——字符串
* ENUM——枚举，存储一组有限的值
* CHAR——限定长度的字符串
  * CHAR(10) 每个字符串的长度都是10
* VARCHAR——可变长度的字符串
  * VARCHAR(99) 每个字符串的长度最多是99