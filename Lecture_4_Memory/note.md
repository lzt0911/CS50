# Lecture 4
## Pixel Art
* Pixels(像素) are squares, individual dots, of color that are arranged on an up-down, left-right grid.
* RGB, or red, green, blue, are numbers that represent the amount of each of these colors. 
## Hexadecimal
## Memory
* Disk drivers(硬盘驱动) are just storage space; we can't directly work there. Manipulation and use of data can only take place in RAM(随机存取存储器), so we have to move data there.
* The C language has two powerful operators that relate to memory:
```
& Provides the address of something stored in memory.
* Instructs(指导) the compiler to go to a location in memory.
```
```c
#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%p\n", &n);
    // %p, which allows us to view the address of a location in memory
    // &n can be literally translated as "the address of n"
}
```
## Pointers
* A pointer is a variable that contains the address of some value.
```c
#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
    printf("%i\n", *p);
}
```
*  A pointer is usually stored as an 8-byte value(64位操作系统).
*  An array's name, is actually just a pointer to its first element.
```c
int *px, py;
// px is a pointer
// py is a integer

int *px, *py;
// px and py both are pointers
```
## Strings
* `string s = "HI!"` can be represented as follows:
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_4_Memory/images/image.png)
s tells the compiler where the first byte of the string exists in memory.
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
}
```
```c
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    // The cs50 library includes a struct as follows: typedef char *string
    printf("%s\n", s);
}
```
## Pointer Arithmetic(算术)
```c
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);

    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
}
```
## String Comparison
* Utilizing the `==` operator in an attempt to compare strings will attempt to compare the memory locations of the strings instead of the characters therein. Accordingly, we recommended the use of `strcmp`.
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_4_Memory/images/image-1.png)
## Copying
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get a string
    string s = get_string("s: ");

    // Copy string's address
    string t = s;

    // Capitalize first letter in string
    t[0] = toupper(t[0]);

    // Print string twice
    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
```
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_4_Memory/images/image-2.png)
* `malloc` allows you to allocate a block of a specific size of memory. 
* `free` allows you to tell the compiler to free up that block of memory you previously allocated.
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Get a string
    char *s = get_string("s: ");
    // NULL means the address 0
    if (s == NULL)
    {
        return 1;
    }

    // Allocate memory for another string
    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
    }

    // Copy string into memory
    strcpy(t, s);

    // Capitalize copy
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    // Print strings
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // Free memory
    free(t);
    return 0;
}
```
## Malloc and Valgrind
* Valgrind is a tool that can check to see if there are memory-related issues with your programs wherein you utilized malloc. Specifically, it checks to see if you free all the memory you allocated.
```
valgrind ./memory
```
## Garbage Values
## Swap
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_4_Memory/images/image-3.png)
```c
#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
```
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_4_Memory/images/image-5.png)
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_4_Memory/images/image-4.png)
## Overflow
* A heap overflow is when you overflow the heap, touching areas of memory you are not supposed to.
* A stack overflow is when too many functions are called, overflowing the amount of memory available.
* Both of these are considered buffer overflows.
## scanf
```
clang -o get -Wno-uninitialized get.c
// 告诉编译器忽略未初始化变量
```
* `scanf` is a built-in function that can get user input.
```c
#include <stdio.h>

int main(void)
{
    int x;
    printf("x: ");
    scanf("%i", &x);
    printf("x: %i\n", x);
}
```
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(4);
    if (s == NULL)
    {
        return 1;
    }
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
    free(s);
    return 0;
}
```
```c
#include <stdio.h>

int main(void)
{
    char s[4];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}
```
* Sometimes, the compiler or the system running it may allocate more memory than we indicate. Fundamentally, though, the above code is unsafe. We cannot trust that the user will input a string that fits into our pre-allocated memory.
## File I/O
* `fopen()` opens a file and returns a file pointer to it. Always check the return value to make sure you don't get back NULL.
    ```
    FILE *ptr = fopen(<filename>, <operation>);
    operation:
    "r": read
    "w": write
    "a": append 
    ```
* `fclose()` closes the file pointed to by the given file pointer.
    ```
    fclose(<file pointer>);
    ```
* `fgetc()` reads and returns the next character from the file pointed to. The operation of the file pointer passed in as a parameter must be "r" for read, or you will suffer an error.
    ```
    char ch = fgetc(<file pointer>);
    ```
    ```c
    char ch;
    while ((ch = fgetc(ptr)) != EOF)
        printf("%c", ch); // cat command
    ```
* `fputc()` writes or appends the specified character to the pointed-to file.
    ```
    fputc(<character>, <file pointer>);
    ```
    ```c
    char ch;
    while ((ch = fgetc(ptr)) != EOF)
        fputc(ch, ptr2); // cp command
    ```
* `fread()` reads < qty > units of size < size > from the file pointed to and stores them in memory in a buffer(usually an array) pointer to by < buffer >.
    ```
    fread(<buffer>, <size>, <qty>, <file pointer>);

    // size: 将文件划分为最小块，每块的大小是多少（例如：文本文件的最小块是char，即1 byte；图片文件的最小块是像素，即3 bytes）
    // qty: 一次读出多少块
    ```
* `fwrite()` writes < qty > units of size < size > to the file pointed to and by reading them from a buffer(usually an array) pointer to by < buffer >.
    ```
    fwrite(<buffer>, <size>, <qty>, <file pointer>);
    ```
* `fgets()` reads a full string from a file.
* `fputs()` writes a full string to a file.
* `fprintf()` writes a formatted string to a file.
* `fseek()` allows you rewind or fast-forword within a file(移动文件指针的位置).
  ```
  int fseek(FILE *stream, long offset, int whence);

  offset: 表示要移动的字节数。可以是正数（向前移动）或负数（向后移动）
  whence: 指定 offset 的基准位置, 常见的取值有：
  SEEK_SET：从文件开头开始计算偏移量。
  SEEK_CUR：从当前文件指针位置开始计算偏移量。
  SEEK_END：从文件末尾开始计算偏移量。
  ```
* `ftell()` tells you at what (byte) position you are at within a file.
* `feof()` tells you whether you've read to the end of a file.
* `ferror()` indicates whether an error occured in working within a file.
```C
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Open CSV file
    FILE *file = fopen("phonebook.csv", "a"); // a为append
    if (!file)
    {
        return 1;
    }

    // Get name and number
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    // Print to file
    fprintf(file, "%s,%s\n", name, number);

    // Close file
    fclose(file);
}
```
```c
#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "rb"); // "rb"以二进制只读模式打开
    FILE *dst = fopen(argv[2], "wb");

    BYTE b;

    // fread 从src中读取1 byte内容到b中
    // fread 返回成功读取的字节数
    while (fread(&b, sizeof(b), 1, src) !=0)
    {
        fwrite(&b, sizeof(b), 1, dst);
        // fwrite 将b中内容写入dst中，每次写入1 byte
    }

    fclose(dst);
    fclose(src);
}
```
## typedef
* The C keyword `typedef` provides a way to create a shorthand or rewritten name for data types.
* The basic idea is to first define a type in the normal way, then alias it to something else.
```
typedef <old name> <new name>;
```
## Call Stack
* When you call a function, the system sets aside space in memory for that function to do its necessary work. We frequently call such chunks of memory stack frames(帧) or function frames.
* These frames are arranged in a stack. The frame for the most recently called function is always on the top of the stack.
* When a new function is called, a new frame is pushed onto the top of the stack and becomes the active frame.
* When a function finished its work, its frame is popped off of the stack, and the frame immediately below it becomes the new, active, function on the top of the stack. This function picks up immediately where it left off.