#include <cs50.h>
#include <stdio.h>

int get_digit_sum(int number);

int main(void)
{
    // 获取用户输入
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);

    // checksum
    int sum = 0;   // 按算法求和
    int digit = 0; // 数字位数
    int d1 = 0;    // 最高位
    int d2 = 0;    // 次高位
    while (number > 0)
    {
        digit++;
        d2 = d1;
        d1 = number % 10;
        sum += get_digit_sum(d1);
        number /= 10;
        if (number <= 0)
        {
            break;
        }
        digit++;
        d2 = d1;
        d1 = number % 10;
        sum += get_digit_sum(2 * d1);
        number /= 10;
    }

    // 结果判断
    if (sum % 10 == 0)
    {
        if (digit == 15 && d1 == 3 && (d2 == 4 || d2 == 7))
        {
            printf("AMEX\n");
        }
        else if (digit == 16 && d1 == 5 && d2 >= 1 && d2 <= 5)
        {
            printf("MASTERCARD\n");
        }
        else if ((digit == 13 || digit == 16) && d1 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int get_digit_sum(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}
