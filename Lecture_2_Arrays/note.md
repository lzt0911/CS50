# Lecture 2
## Compiling
```
make hello
==>
clang -o hello hello.c
clang -o hello hello.c -lcs50
```
* preprocessing（预处理） is where the header files in your code, designated by a `#` (such as `#include <cs50.h>`) are effectively copied and pasted into your file. 
* compiling（编译） is where your program is converted into assembly code（汇编语言）.
* assembling（汇编） involves the compiler converting your assembly code into machine code. 
* during the linking（链接） step, code from your included libraries are converted also into machine code and combined with your code.
## Debugging
* using printf
* using debugger
  * set a breakpoint
  * debug50 ./buggy
## Arrays
* Arrays are a way of storing data back-to-back in memory such that this data is easily accessible.
* We cannot assign one array to another using the assignment operator. Instead, we must use a loop to copy over the elements one at a time.
* Arrays are passed by reference. The callee receives the actual array, not a copy of it.
```c
#include <cs50.h>
#include <stdio.h>

// Constant
const int N = 3;

// Prototype
float average(int length, int array[]);

int main(void)
{
    // Get scores
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    // Print average
    printf("Average: %f\n", average(N, scores));
}

float average(int length, int array[])
{
    // Calculate average
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}
```
```c
int arr[] = {1, 2, 3}; // 自动计算数组大小为3
```
## Strings
* A string is simply an array of variables of type char: an array of characters.
* A string is an array of characters that begins with the first character and ends with a special character called a NUL character（\0）.
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string words[2];

    words[0] = "HI!";
    words[1] = "BYE!";

    printf("%s\n", words[0]);
    printf("%s\n", words[1]);
    printf("%c %c %c\n", words[0][0], words[0][1], words[0][2]);
}
```
## String Length
```c
#include <cs50.h>
#include <stdio.h>

int string_length(string s);

int main(void)
{
    // Prompt for user's name
    string name = get_string("Name: ");
    int length = string_length(name);
    printf("%i\n", length);
}

int string_length(string s)
{
    // Count number of characters up until '\0' (aka NUL)
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
    return n;
}
```
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt for user's name
    string name = get_string("Name: ");
    int length = strlen(name);
    printf("%i\n", length);
}
```
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
```
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i])); // toupper automatically knows to uppercase only lowercase characters
    }
    printf("\n");
}
```
## Command-Line Arguments
* Command-line arguments are those arguments that are passed to your program at the command line.
```c
#include <cs50.h>
#include <stdio.h>

// argc, the number of command line arguments
// argv which is an array of the characters passed as arguments at the command line.
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
        // printf("%s\n", argv[0]); // ./greet
        // printf("%s\n", argv[2]); // Segmentation fault
    }
    else
    {
        printf("hello, world\n");
    }
}
```
## Exit Status
```
查看程序返回值
echo $?
```
## Cryptography密码学
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_2_Arrays/images/image.png?raw=true)
## 补充
```
// 四舍五入函数
round(num);

// 判断是否为空格
isspace(c);
```