def calculate_check_sum(number):
    sum = 0
    while number:
        sum += int(number % 10)
        number /= 10
    return sum


number = input("Number: ")
check_sum = 0
for i in range(len(number) - 1, -1, -2):
    check_sum += calculate_check_sum(int(number[i]))
    i -= 1
    if i >= 0:
        check_sum += calculate_check_sum(2 * int(number[i]))

if check_sum % 10 == 0:
    sub_number = number[0:2]
    if len(number) == 15 and (sub_number == "34" or sub_number == "37"):
        print("AMEX")
    elif len(number) == 16 and (sub_number == "51" or sub_number == "52" or sub_number == "53" or sub_number == "54" or sub_number == "55"):
        print("MASTERCARD")
    elif (len(number) == 13 or len(number) == 16) and number[0] == '4':
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
