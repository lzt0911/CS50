# Lecture 6
## Python
Python is an interpreted language, where you need not separately compile your program. Instead, you run your program in the Python Interpreter.
[Python documentation](https://docs.python.org/3/library/functions.html)
## Hello
* python可以没有main函数
* python从上至下、从左至右的执行
```python
# A program that says hello to the world

print("hello, world")
```
## Speller
```python
# Words in dictionary
words = set()


def check(word):
    """Return true if word is in dictionary else false"""
    return word.lower() in words


def load(dictionary):
    """Load dictionary into memory, returning true if successful else false"""
    with open(dictionary) as file:
        words.update(file.read().splitlines())
    return True


def size():
    """Returns number of words in dictionary if loaded else 0 if not yet loaded"""
    return len(words)


def unload():
    """Unloads dictionary from memory, returning true if successful else false"""
    return True
```
## Filter
```python
# Blurs an image

# imports modules Image and ImageFilter from a library called PIL
from PIL import Image, ImageFilter

# Blur image
before = Image.open("bridge.bmp")
after = before.filter(ImageFilter.BoxBlur(1))
after.save("out.bmp")
```
```python
# Finds edges in an image

from PIL import Image, ImageFilter

# Find edges
before = Image.open("bridge.bmp")
after = before.filter(ImageFilter.FIND_EDGES)
after.save("out.bmp")
```
```python
# Find faces in picture
# https://github.com/ageitgey/face_recognition/blob/master/examples/find_faces_in_picture.py

from PIL import Image
# pip install face_recognition
import face_recognition

# Load the jpg file into a numpy array
image = face_recognition.load_image_file("office.jpg")

# Find all the faces in the image using the default HOG-based model.
# This method is fairly accurate, but not as accurate as the CNN model and not GPU accelerated.
# See also: find_faces_in_picture_cnn.py
face_locations = face_recognition.face_locations(image)

for face_location in face_locations:

    # Print the location of each face in this image
    top, right, bottom, left = face_location

    # You can access the actual face itself like this:
    face_image = image[top:bottom, left:right]
    pil_image = Image.fromarray(face_image)
    pil_image.show()
```
## CS50 Library
```python
from CS50 import get_float, get_int, get_string
```
## Strings
```python
# get_string and print, with concatenation

from cs50 import get_string

# 法一，沿用C中的方法
answer = get_string("What's your name? ")
# 法二，使用内置函数
answer = input("What's your name? ")

print("hello, " + answer)
print("hello,", answer) # python会在变量之间自动补空格
print(f"hello, {answer}")
```
```python
text = input("...")
text.strip() # 移除字符串开始和结束处的指定字符（默认为空白符，包括空格、换行符 \n、制表符 \t 等）
# 如果需要移除其他特定字符，可以在 strip() 方法中指定这些字符。
text.lower() # 将字符串全部转换为小写
text.upper() # 将字符串全部转换成大写
text.capitalize() # 字符串第一个字符大写，其余字符小写
words = text.split() # 以空格字符分割，words为list
print(words[2:]) # 从第2个元素开始到最后一个元素
print(words[1:3]) # 打印[1, 3)元素
```
```python
# 字符串切片
s = "Hello, World!"
# 提取索引1到4的字符（索引从0开始）
substring = s[1:5]  # "ello"

# 提取从索引7开始到字符串末尾的字符
substring = s[7:]  # "World!"

# 提取从字符串开始到索引7的字符
substring = s[:8]  # "Hello, W"

# 每两个字符提取一个字符
substring = s[::2]  # "Hlo ol!"
```
```python
# re.split() 是 Python 中 re 模块（正则表达式模块）提供的一个函数
# 它用于根据匹配正则表达式的模式来分割字符串。这个函数会返回一个列表，其中包含了被分割的部分
sentences = len(re.split('[.!?]', text)) - 1 # 以句号、感叹号、问号分隔
# 减1是因为分割后的最后一个是空字符串
# 原始字符串以"."结尾，所以最后一个分隔符后面没有更多的字符
words = len(re.split(' ', text)) # 以空格分隔
```
## Variables
```python
# You need not declare the type of the variable.
count = 0
count += 1
count++ # 不可使用
```
## Types
* bool
* float
* int
* str
* Notice that long and double are missing. 
* Python will handle what data type should be used for larger and smaller numbers.
* range
* list 数组
* tuple
* dict
* set 去重
## Calculator
```python
# Addition with int [using get_int]

from cs50 import get_int

# Prompt user for x
x = get_int("x: ")

# Prompt user for y
y = get_int("y: ")

# Perform addition
print(x + y)
```
```python
# Addition with int [using get_int]

import cs50

# Prompt user for x
x = cs50.get_int("x: ")

# Prompt user for y
y = cs50.get_int("y: ")

# Perform addition
print(x + y)
```
```python
# Addition with int [using input]

# Prompt user for x
# input获取到的输入都是str类型，需要将其转化为int类型
x = int(input("x: "))

# Prompt user for y
y = int(input("y: "))

# Perform addition
print(x + y)
```
## Conditionals
```
&& --> and
|| --> or
!  --> not
```
```python
# Conditionals, Boolean expressions, relational operators

from cs50 import get_int

# Prompt user for integers
x = get_int("What's x? ")
y = get_int("What's y? ")

# Compare integers
if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")
```
```python
s = input("s: ")
t = input("t: ")

# python可直接用==比较字符串内容是否相等
if s == t:
    print("Same")
else:
    print("Different")
```
```python
# Logical operators

from cs50 import get_string

# Prompt user to agree
s = get_string("Do you agree? ")

# Check whether agreed
if s == "Y" or s == "y":
    print("Agreed.")
elif s == "N" or s == "n":
    print("Not agreed.")
```
```python
letters_only = True if input().isalpha() else False
```
## Object-Oriented Programming
```python
# Logical operators, using lists

from cs50 import get_string

# Prompt user to agree
s = get_string("Do you agree? ").lower()

# Check whether agreed
if s.lower() in ["y", "yes"]:
    print("Agreed.")
elif s.lower() in ["n", "no"]:
    print("Not agreed.")
```
## Loops
```python
# Demonstrates while loop
i = 0
while i < 3:
    print("meow")
    i += 1

# for loop
# range(3): 0, 1, 2
for i in range(3):
    print("meow")
```
```python
# Uppercases string one character at a time

before = input("Before: ")
print("After:  ", end="")
# end= is used to pass a parameter to the print function that continues the line without a line ending.
for c in before:
    print(c.upper(), end="")
print()

# Uppercases string all at once
after = before.upper()
print(f"After:  {after}")
```
```python
# [0, 100)以2为间隔
for x in range(0, 100, 2)
    print(x)
```
## Abstraction
* All functions are introduced with the def keyword
* Also, no need for main; the interpreter reads from top to bottom!
* If you wish to define main nonetheless(尽管如此), you must at the very end of your code have:
```python
if __name__ == "__main__":
    main()
```
```python
# Abstraction with parameterization

def main():
    meow(3)


# Meow some number of times
def meow(n):
    for i in range(n):
        print("meow")


main()
```
## Truncation and Floating Point Imprecision(截断和浮点不精确)
```python
# Division with integers, demonstration lack of truncation

# Prompt user for x
x = int(input("x: "))

# Prompt user for y
y = int(input("y: "))

# Divide x by y
z = x / y
print(z) # 会打印浮点数
print(f"{z:.50f}") # 打印小数点后50位
```
* python仍然存在浮点数不精确的问题，但不会出现integer overflow
## Exceptions异常
```python
# Implements get_int with a loop

def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Not an integer") # 或pass
            # raise ValueError("Not an integer")


def main():

    # Prompt user for x
    x = get_int("x: ")

    # Prompt user for y
    y = get_int("y: ")

    # Perform addition
    print(x + y)


main()
```
## Mario
```python
# Prints a column of n bricks with a loop

from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0:
        break

for i in range(n):
    print("#")
```
```python
# Prints a row of 4 question marks with a loop

for i in range(4):
    print("?", end="")
print()

# Prints a row of 4 question marks without a loop

print("?" * 4)
```
```python
# Prints a 3-by-3 grid of bricks with loops

for i in range(3):
    for j in range(3):
        print("#", end="")
    print()

for i in range(3):
    print("#" * 3)
```
## Lists
* 类似数组，不过由python来分配内存，并自动增大或缩小
```python
# Averages three numbers using a list and a loop

from cs50 import get_int

# Get scores
scores = []
for i in range(3):
    score = get_int("Score: ")
    scores.append(score)
    # scores = scores + [score]

# Print average
average = sum(scores) / len(scores)
print(f"Average: {average}")
```
```python
nums = [x for x in range(500)]
nums.insert(4, 5) # 将5写入第4个位置
nums[len(nums):] = [5] # 在列表末尾追加5
nums.pop(0) # 移除第一个元素，若不指定则默认移除最后一个元素

```
## Tuples元组
* Tuples are ordered, immutable(不可变) sets of data
```python
presidents = [
    ("George Washington", 1789),
    ("John Adams", 1797),
    ("Thomas Jefferson", 1801),
    ("James Madison", 1809)
]

for prez, year in presidents:
    print("In {1}, {0} took office".format(prez, year))
```
## Searching and Dictionaries
```python
# Implements linear search for names using loop

# A list of names
names = ["Carter", "David", "John"]

# Ask for name
name = input("Name: ")

# Search for name
for n in names:
    if name == n:
        print("Found")
        break
else: # 如果没有运行break而结束循环
    print("Not found")
```
```python
# Implements linear search for names using `in`

# A list of names
names = ["Carter", "David", "John"]

# Ask for name
name = input("Name: ")

# Search for name
if name in names:
    print("Found")
else:
    print("Not found")
```
```python
# Implements a phone book as a list of dictionaries, without a variable

from cs50 import get_string

# people是一个list
# list中的每一个元素都是一个dictionary
# 每个dictionary都有两个键值对
people = [
    {"name": "Carter", "number": "+1-617-495-1000"},
    {"name": "David", "number": "+1-617-495-1000"},
    {"name": "John", "number": "+1-949-468-2750"},
]

# Search for name
name = get_string("Name: ")
for person in people:
    if person["name"] == name:
        print(f"Found {person['number']}")
        break
else:
    print("Not found")
```
```python
# Implements a phone book using a dictionary

from cs50 import get_string

people = {
    "Carter": "+1-617-495-1000",
    "David": "+1-617-495-1000",
    "John": "+1-949-468-2750",
}

# Search for name
name = get_string("Name: ")
# name获取的是每一个key
if name in people:
    print(f"Number: {people[name]}")
else:
    print("Not found")
```
```python
books = []

# Add three books to shelf
for i in range(3):
    book = dict() # 创建空白dictionary
    book["title"] = input("Enter a title: ")
    book["author"] = input("Enter an author: ")
    books.append(book)

# print list of books
for book in books:
    print(book)
    print(book.keys())
    print(f"{book["author"]} wrote {book["title"]}.")

# 遍历所有value和key
# dict.items()返回一个包含字典键值对的视图对象。每个键值对是一个元组(key, value)
for title, author in books.items():
    print(author)
```
## Command-Line Arguments
```python
# Prints a command-line argument

from sys import argv

if len(argv) == 2:
    print(f"hello, {argv[1]}")
else:
    print("hello, world")
```
```python
# Printing command-line arguments, indexing into argv

from sys import argv

for i in range(len(argv)):
    print(argv[i])

for arg in argv:
    print(arg)
```
## Exit Status
```python
# Exits with explicit value, importing sys

import sys

if len(sys.argv) != 2:
    print("Missing command-line argument")
    sys.exit(1)

print(f"hello, {sys.argv[1]}")
sys.exit(0)
```
## Third-Party Libraries
```python
import csv

csv.DicReader(...) # 读取csv文件的每一行作为字典，其中第一行作为key
csv.reader(...)
```
```python
from csv import DictReader

DictReader(...)
```
## File Reading and Writing
```python
with open(FILENAME) as file:
    text = file.read() # 读取文件全部内容
```
```python
import csv

books = []

# Add books to shelf by reading from books.csv
with open("books.csv") as file:
    reader = csv.DictReader(file)
    for row in reader:
        books.append(row)
# 跳出with代码段后，file自动close

# Print books
for book in books:
    print(book)
```
## Objects
* You define a type of object using the class keyword in Python.
* Classes require an initialization function, also more-generally known as constructor（构造函数）, which sets the starting values of the properties（属性） of the object.
* In defining each method of an object, self should be its first parameter, which stipulates(规定) on what object the method is called.
```python
class Student():
    def __init__(self, name, id):
        self.name = name
        self.id = id
    def changeID(self, id):
        self.id = id
    def print(self):
        print("{} - {}".format(self.name, self.id))

jane = Student("Jane", 10)
jane.print()
jane.changeID(20)
jane.print( )
```