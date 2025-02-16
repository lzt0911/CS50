#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool check_key(string key);
void encrypt(string text, string key);

int main(int argc, string argv[])
{
    // 检查输入参数个数
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // 检查key有效
    if (!check_key(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // 获取用户输入原始字符串
    string text = get_string("plaintext:  ");
    // 字符串加密
    encrypt(text, argv[1]);
    // 输出加密后字符串
    printf("ciphertext: %s\n", text);
    return 0;
}

bool check_key(string key)
{
    int len = strlen(key);
    bool count[26] = {false}; // 记录字符是否出现过
    if (len != 26)
    {
        return false; // key必须是26个字母
    }
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
        if (count[toupper(key[i]) - 'A'])
        {
            return false; // key中的字母不能重复
        }
        count[toupper(key[i]) - 'A'] = true;
    }
    return true;
}

void encrypt(string text, string key)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = toupper(key[text[i] - 'A']);
            }
            else
            {
                text[i] = tolower(key[text[i] - 'a']);
            }
        }
    }
}
