# Lecture 3
## Linear Search
```
For i from 0 to n-1
    If 50 is behind doors[i]
        Return true
Return false
```
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // An array of strings
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    // Search for string
    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```
## Binary Search
```
Assuming that the values within the lockers have been arranged from smallest to largest

If no doors left
    Return false
If 50 is behind doors[middle]
    Return true
Else if 50 < doors[middle]
    Search doors[0] through doors[middle - 1]
Else if 50 > doors[middle]
    Search doors[middle + 1] through doors[n - 1]
```
## Running Time
* 上界（最差情况）
  * O(n^2)
  * O(nlogn)
  * O(n)
  * O(logn)
  * O(1)
* 下界（最好情况）
  * 用&Omega;表示 
* 若上下界相同，则用&theta;表示
## Data Structures
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[3];

    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-617-495-1000";

    people[2].name = "John";
    people[2].number = "+1-949-468-2750";

    // Search for name
    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```
## Sorting
* selection sort
  ```
  For i from 0 to n–1
    Find smallest number between numbers[i] and numbers[n-1]
    Swap smallest number with numbers[i]
  ```
  * 时间复杂度
    * 最差情况：O(n^2)
    * 最好情况：&Omega;(n^2)
* bubble sort
  ```
  Repeat n-1 times
    For i from 0 to n–2
        If numbers[i] and numbers[i+1] out of order
            Swap them
    If no swaps
        Quit
  ```
  * 时间复杂度
    * 最差情况：O(n^2)
    * 最好情况：&Omega;(n)
* merge sort
  ```
  把n个数一层层对半分，需要分logn次
  每一次都需要访问n个数对其进行排序
  If only one number
    Quit
  Else
    Sort left half of number
    Sort right half of number
    Merge sorted halves
  ```
  ![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_3_Algorithms/images/image.png)
  * 时间复杂度
    * 最差情况：O(nlogn)
    * 最好情况：&Omega;(nlogn)
## Recursion递归
* Recursion is a concept within programming where a function calls itself.
```c
#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    // Get height of pyramid
    int height = get_int("Height: ");

    // Draw pyramid
    draw(height);
}

void draw(int n)
{
    // If nothing to draw
    if (n <= 0)
    {
        return;
    }

    // Draw pyramid of height n - 1
    draw(n - 1);

    // Draw one more row of width n
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
```
