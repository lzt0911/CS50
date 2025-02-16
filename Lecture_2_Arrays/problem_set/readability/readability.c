#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define FORMULA(L, S) 0.0588 * L - 0.296 * S - 15.8
// L is the average number of letters per 100 words in the text:
// that is, the number of letters divided by the number of words, all multiplied by 100.
// S is the average number of sentences per 100 words in the text:
// that is, the number of sentences divided by the number of words, all multiplied by 100.

int get_grade(string text);

int main(void)
{
    // 获取用户输入
    string text = get_string("Text: ");

    // 计算文本等级
    int grade = get_grade(text);

    // 输出等级
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int get_grade(string text)
{
    int letters = 0;
    int sentences = 0;
    int words = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
        if (isalpha(text[i]))
        {
            letters++;
        }
        if (text[i] == ' ' || i == len - 1)
        {
            words++;
        }
    }
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;

    return round(FORMULA(L, S)); // 四舍五入
}
