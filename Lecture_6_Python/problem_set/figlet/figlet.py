import sys
from pyfiglet import Figlet
import random


if len(sys.argv) == 1:
    input_str = input("Input: ")
    figlet = Figlet()
    # 获取随机format
    random_format_number = random.randint(0, len(figlet.getFonts()) - 1)
    figlet.setFont(font=figlet.getFonts()[random_format_number])
    print("Output: ")
    print(figlet.renderText(input_str))
elif len(sys.argv) == 3:
    figlet = Figlet()
    if (sys.argv[1] == "-f" or sys.argv[1] == "--font") and sys.argv[2] in figlet.getFonts():
        input_str = input("Input: ")
        figlet.setFont(font=sys.argv[2])
        print("Output: ")
        print(figlet.renderText(input_str))
    else:
        print("Invalid usage")
        sys.exit(1)
else:
    print("Invalid usage")
    sys.exit(1)
