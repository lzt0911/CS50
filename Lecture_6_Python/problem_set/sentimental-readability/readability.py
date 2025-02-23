from cs50 import get_string
import re


def get_grade(text):
    # re.split() 是 Python 中 re 模块（正则表达式模块）提供的一个函数
    # 它用于根据匹配正则表达式的模式来分割字符串。这个函数会返回一个列表，其中包含了被分割的部分
    sentences = len(re.split('[.!?]', text)) - 1
    # 减1是因为分割后的最后一个是空字符串
    # 原始字符串以"."结尾，所以最后一个分隔符后面没有更多的字符
    # 如果你不想在结果中包含空字符串，可以使用列表推导式来过滤它们
    # tokens = [token for token in re.split(r'[.?!]', text) if token]
    words = len(re.split(' ', text))
    letters = 0
    for c in text:
        if c.isalpha():
            letters += 1
    L = letters / words * 100
    S = sentences / words * 100
    return round(0.0588 * L - 0.296 * S - 15.8)


text = get_string("Text: ")
grade = get_grade(text)

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
