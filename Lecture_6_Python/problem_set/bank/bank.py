str = input("Greeting: ").strip().lower()

if str[0:len("hello")] == "hello":
    print("$0")
elif str[0] == "h":
    print("$20")
else:
    print("$100")
