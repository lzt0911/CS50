# Lecture 1 
## Hello World
* We can convert source code into machine code using a very special piece of software called a compiler.
* We will be using three commands to write, compile, and run our first program
  ```
  // creates a file and allows us to type instructions for this program.
  code hello.c

  // compiles the file from our instructions in C and creates an executable file called hello
  make hello

  // runs the program called hello
  ./hello
  ```
## Functions
* The statement at the start of the code `#include <stdio.h>` is a very special command that tells the compile that you want to use the capabilities(能力) of a library called `stdio.h`, a header file. This allows you, among many other things, to utilize the `printf` function.
* Libraries are collections of pre-written functions that others have written in the past that we can utilize in our code.
* 好的编码格式：main函数在最上面，其他函数在下面。
## Variables
* A variable is a name for some value that can change.
* int - 4 bytes - 32 bits
  * signed int: $-2^{31}$ ~ $2^{31} - 1$
  * unsigned int: 0 ~ $2^{32} - 1$
* char - 1 byte - 8 bits
* float - 4 bytes - 32 bits
* double - 8 types - 64 bits
* void
* bool 非C内置类型
* string 非C内置类型
* variable scope
  * local variables
  * global variables
  * local variables in C are passed by value in function calls. When a variable is passed by value, the callee receives a copy of the passed variable, not the variable itself. That means that the variable in the caller is unchanged unless overwritten. 
```c
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);
}
```
* in this course, we use:
  * %s - string
  * %c - char
  * %f - float
  * %i - int
  * %li - long
## Conditionals
```C
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");

    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }
}
```
```C
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user to agree
    char c = get_char("Do you agree? ");

    // Check whether agreed
    if (c == 'Y' || c == 'y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'N' || c == 'n')
    {
        printf("Not agreed.\n");
    }
}
```
```c
int x = get_int("x is: ");
switch(x)
{
    case 1:
        printf("One!\n");
        break;
    case 2:
        printf("Two!\n");
        break;
    case 3:
        printf("Three!\n");
        break;
    default:
        printf("Sorry!\n");
}
```
## Loops
```c
#include <stdio.h>

int main(void)
{
    int i = 0;
    while (i < 3)
    {
        printf("meow\n");
        i++;
    }
}
```
```c
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("meow\n");
    }
}
```
```c
#include <stdio.h>

void meow(int n);

int main(void)
{
    meow(3);
}

// Meow some number of times
void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
```
```c
int main(void)
{
    const int n = 3;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
```
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
```
## Operators and Abstraction
```c
#include <cs50.h>
#include <stdio.h>

int add(int a, int b);

int main(void)
{
    // Prompt user for x
    int x = get_int("x: ");

    // Prompt user for y
    int y = get_int("y: ");

    // Perform addition
    printf("%i\n", add(x, y));
}

int add(int a, int b)
{
    return a + b;
}
```
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    float z = x / y;
    printf("%f\n", z); // 0.000000

    float z2 = (float) x / (float) y;
    printf("%f\n", z2); // 0.333333
    printf("%.5f\n", z2); // 0.33333 显示5位小数
    printf("%.20f\n", z2); // 0.33333334326744079590 浮点数不精确，有限的内存无法表示无限多的实数

    double z3 = (double) x / (double) y;
    printf("%.20f\n", z3); // 0.33333333333333331483

    // 数学运算中涉及到一个浮点数，将会使整个算术表达式提升为浮点数学运算
}

```
## Linux and the Command line
* `cd` for changing our current directory (folder)
  * `cd .` 当前目录
  * `cd ..` 上级目录
  * `cd` 回到home目录
* `cp` for copying files and directories
  * `cp -r` copy a directory
* `ls` for listing files in a directory
* `mkdir` for making a directory
* `mv` for moving (renaming) files and directories
* `rm` for removing (deleting) files
  * `rm -f` force remove
  * `rm -r `remove a directory
* `rmdir` for removing (deleting) directories
* `pwd` present working directory
* `clear` or `ctrl + l` clear the screen
## Comments
## Types
* 时间：从1970年1月1日开始 
## Magic Numbers
```c
// 将replacement替换成name
#define NAME REPLACEMENT

#define PI 3.14
#define COURSE "CS50"

//定义函数
#define MAX(a,b) (a>b)?a:b  //取两个数最大值
#define MIN(a,b) (a<b)?a:b  //取两个数最小值

```