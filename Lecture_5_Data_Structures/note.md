# Lecture 5
## Data Structures
* Data structures essentially are forms of organization in memory.
## Stacks and Queues
* Queue
  * FIFO(first in first out)
  * enqueue and dequeue
  ```c
  // 使用数组实现队列 
  typedef struct queue
  {
    VALUE array[CAPACITY];
    int front; // 队列中第一个元素的序号
    int size; // 队列中元素个数
  }
  queue;
  ```
  ```c
  // 使用双向链表实现队列
  typedef struct queue
  {
    list *head; // 队首
    list *tail; // 队尾
  }
  queue;

  typedef struct list
  {
    VALUE val;
    struct list *prev;
    struct list *next;
  }
  list;
  ```
* Stack
  * LIFO(last in first out)
  * push and pop
  ```c
  // 使用数组实现栈
  typedef struct stack
  {
    VALUE array[CAPACITY];
    int top; // 栈顶元素 
  }
  stack;
  ```
  ```c
  // 使用单链表实现栈
  typedef struct stack
  {
    list *head; // 栈顶
  }
  stack;

  typedef struct list
  {
    VALUE val;
    struct list *next;
  }
  list;
  ```
## Linked Lists
```c
// single-linked list
typedef struct node
{
    int number;
    struct node *next;
}
node;

// double-linked list
typedef struct node
{
    int number;
    struct node *pre;
    struct node *next;
} 
node;
```
```c
// 前插
// Prepends numbers to a linked list, using while loop to print

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    // Memory for numbers
    node *list = NULL;

    // For each command-line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert argument to int
        int number = atoi(argv[i]);

        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        // Prepend node to list
        n->next = list;
        list = n;
    }

    // Print numbers
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

    // Free memory
    ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
```
```c
// 后插
// Implements a list of numbers using a linked list

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    // Memory for numbers
    node *list = NULL;

    // For each command-line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert argument to int
        int number = atoi(argv[i]);

        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        // If list is empty
        if (list == NULL)
        {
            // This node is the whole list
            list = n;
        }

        // If list has numbers already
        else
        {
            // Iterate over nodes in list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list
                if (ptr->next == NULL)
                {
                    // Append node
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
```
```c
// 按value排序列表
// Implements a sorted list of numbers using a linked list

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    // Memory for numbers
    node *list = NULL;

    // For each command-line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert argument to int
        int number = atoi(argv[i]);

        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        // If list is empty
        if (list == NULL)
        {
            list = n;
        }

        // If number belongs at beginning of list
        else if (n->number < list->number)
        {
            n->next = list;
            list = n; 
        }

        // If number belongs later in list
        else
        {
            // Iterate over nodes in list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list
                if (ptr->next == NULL)
                {
                    // Append node
                    ptr->next = n;
                    break;
                }

                // If in middle of list
                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
```
```
递归删除整个链表
1、If you've reached a null pointer, stop.
2、Delete the rest of the list.
3、Free the current node.
```
## Trees
```c
// 二叉搜索树
// Implements a list of numbers as a binary search tree

#include <stdio.h>
#include <stdlib.h>

// Represents a node
typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

void free_tree(node *root);
void print_tree(node *root);

int main(void)
{
    // Tree of size 0
    node *tree = NULL;

    // Add number to list
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    tree = n;

    // Add number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(tree);
        return 1;
    }
    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    tree->left = n;

    // Add number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(tree);
        return 1;
    }
    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    tree->right = n;

    // Print tree
    print_tree(tree);

    // Free tree
    free_tree(tree);
    return 0;
}

void free_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void print_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    printf("%i\n", root->number);
    print_tree(root->right);
}
```
```c
bool search_tree(node *n, in val)
{
    if (n == NULL)
    {
        return false;
    }
    else if (val < n->number)
    {
        return search_tree(n->left, val);
    }
    else if (val > n->number)
    {
        return search_tree(n->right, val);
    }
    else
    {
        return true;
    }
}
```
## Dictionaries字典
## Hashing and Hash Tables
* A hash function is an algorithm that reduces a larger value to something small and predictable. Generally, this function takes in an item you wish to add to your hash table, and returns an integer representing the array index in which the item should be placed.
* A hash table is an array of pointers to nodes(链表数组).
* Collisions(哈希冲突) are when you add values to the hash table, and something already exists at the hashed location.
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_5_Data_Structures/images/image.png)
```c
typedef struct node
{
    char *name;
    char *number;
    struct node *next;
}

node *table[26];

unsigned int hash(const char *name)
{
    return toupper(name[0]) - 'A';
}

```
* 设计出完美的hash function，可使时间复杂度达到O(1)；大多数情况下的时间复杂度为O(n/k)(k为hash table的长度)。
## Tries前缀树、字典树
* The data to be searched for in the trie is now a roadmap. If you can follow the map from beginning to end, the data exists in the trie. If you can't, it doesn't.
* 时间复杂度为O(1)
* Tries是一个数组树，树的每个节点都是一个数组。
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_5_Data_Structures/images/image-1.png)
```c
typedef struct node
{
    struct node *children[26];
    char *number;
} node;

```
```c
typedef struct node
{
    struct node *paths[10];
    char university[20];
} node;
```
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_5_Data_Structures/images/image-2.png)