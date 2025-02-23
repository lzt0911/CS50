menu = {
    "Baja Taco": 4.25,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

price_sum = 0
while True:
    try:
        dish = input("Item: ")
        for key in menu.keys():
            if dish.lower() == key.lower():
                price_sum += menu[key]
                print(f"Total: ${price_sum:.2f}")
                break
    except EOFError:
        print()
        break
