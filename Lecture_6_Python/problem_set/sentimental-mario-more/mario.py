from cs50 import get_int

num = get_int("Height: ")
while num < 1 or num > 8:
    num = get_int("Height: ")

for i in range(num):
    for j in range(num - i - 1):
        print(" ", end="")
    for j in range(i + 1):
        print("#", end="")
    print("  ", end="")
    for j in range(i + 1):
        print("#", end="")
    print()
