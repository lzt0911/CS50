# 补充
## 四舍五入
```
round(num);
```
## 字符判断
```
isspace(c); // 判断是否为空格
isalnum(c); // 判断一个字符是否是字母或数字
```
## str转换成double
```
double atof(const char *str);
```
## 结构体内存
```
typedef struct
{
    WORD   bfType;
    DWORD  bfSize;
    WORD   bfReserved1;
    WORD   bfReserved2;
    DWORD  bfOffBits;
} __attribute__((__packed__))
BITMAPFILEHEADER;

__attribute__((__packed__)) 是一个 GCC 特定的扩展属性，用于确保结构体的每个成员紧密排列，不进行对齐填充。
这在处理二进制文件格式或硬件协议时非常有用，可以确保结构体的内存布局与文件格式或协议一致。
```
## 解析命令行参数
```
#include <unistd.h>

// 用于解析命令行参数
int getopt(int argc, char *const argv[], const char *optstring);

参数
argc 和 argv：这两个参数是从 main 函数传递过来的，分别表示命令行参数的数量和参数数组。
optstring：一个字符串，指定了程序接受的选项字符。如果选项需要参数，则在选项字符后面加上冒号（:）。

返回值
如果成功解析到一个选项，getopt 返回选项字符。
如果遇到一个不在 optstring 中的选项字符，getopt 返回 ?。
如果所有选项都已解析完毕，getopt 返回 -1。

optind 是全局变量，初始值为 1，表示从 argv[1] 开始解析命令行参数。每当 getopt() 成功解析一个选项后，optind 会自动递增，指向下一个要解析的参数

```
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;

    // 定义选项字符串
    // 'a' 和 'b' 是短选项，'a' 选项需要一个参数，'b' 选项不需要参数
    while ((opt = getopt(argc, argv, "a:b")) != -1) {
        switch (opt) {
            case 'a': // 处理选项 -a
                // 当选项需要参数时，optarg 指向该参数的值
                printf("Option -a with value: %s\n", optarg);
                break;
            case 'b': // 处理选项 -b
                printf("Option -b found\n");
                break;
            case '?': // 处理无效选项
                // 当遇到无效选项时，getopt 会将该选项存储在 optopt 中
                fprintf(stderr, "Unknown option: %c\n", optopt);
                exit(EXIT_FAILURE);
        }
    }

    // 处理非选项参数（即位置参数）
    printf("Remaining arguments:\n");
    for (int i = optind; i < argc; i++) {
        printf("Argument %d: %s\n", i - optind + 1, argv[i]);
    }

    return 0;
}

// 运行
./example -a hello -b extra1 extra2
// 结果
Option -a with value: hello
Option -b found
Remaining arguments:
Argument 1: extra1
Argument 2: extra2
```
## 分配内存
```
#include <stdlib.h>

// 分配内存并初始化为零
void *calloc(size_t nmemb, size_t size);

参数
nmemb：要分配的元素数量。
size：每个元素的大小（以字节为单位）。

int(*image)[width] = calloc(height, width * sizeof(int));
// image是一个指针，指向一个包含 width 个 int 的数组。换句话说，image 是一个二维数组的指针，其中每一行有 width 个 int 元素。
```
## 随机数
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 10; // 随机数范围 [0, 9]

    // 初始化随机数生成器
    srand(time(0));

    // 生成一个介于 [0, n-1] 的随机整数
    int random_number = rand() % n;

    printf("Random number between 0 and %d: %d\n", n - 1, random_number);

    return 0;
}
```
```python
import random

# 返回[a, b]的随机数
random.randint(a, b)
```
## 宏
```
#undef 是一个预处理器指令，用于取消之前定义的宏
```
## 资源使用
```
// 记录程序资源使用情况的数据结构
struct rusage before;

getrusage(RUSAGE_SELF, &before);
// 获取当前进程的资源使用情况，并存储到 before 中
// RUSAGE_SELF 表示获取当前进程的资源使用情况
```
## 艺术化字符
```python
# Figlet 是一个开源的 ASCII 艺术生成工具，它能够将普通的文本转换成大型的、艺术化的字符，这些字符通常用于在终端或文本文件中创建独特的视觉效果。
from pyfiglet import Figlet
import random

input_str = input("Input: ")
figlet = Figlet()
# 获取随机format
random_format_number = random.randint(0, len(figlet.getFonts()) - 1)
figlet.setFont(font=figlet.getFonts()[random_format_number])
print("Output: ")
print(figlet.renderText(input_str))
```
## 打印类
```python
class Jar:
    def __init__(self, capacity=12):
        self.capacity = 0
        if capacity >= 0:
            self.capacity = capacity
        else:
            raise ValueError("capacity can not be negative")

    def __str__(self):
        return "#" * self.capacity

jar = Jar()
print(str(jar))
```
## 从网络获取文件
```python
# 发送一个 GET 请求到指定的 URL
download = requests.get(
    "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
)
# 将字节串（bytes）解码转换为 Unicode 字符串（str）
decoded_content = download.content.decode("utf-8")
# 将字符串按换行符分隔
file = decoded_content.splitlines()
```