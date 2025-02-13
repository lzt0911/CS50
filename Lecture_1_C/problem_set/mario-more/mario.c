#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // 提示用户输入在1~8范围内的height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // 打印
    for (int i = 1; i <= height; i++)
    {
        for (int j = height - i; j > 0; j--)
        {
            printf(" ");
        }
        for (int j = i; j > 0; j--)
        {
            printf("#");
        }
        printf("  ");
        for (int j = i; j > 0; j--)
        {
            printf("#");
        }
        printf("\n");
    }
}
