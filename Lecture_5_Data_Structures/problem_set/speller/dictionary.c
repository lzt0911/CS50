// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = LENGTH * 27;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // 计算hash
    int key = hash(word);

    // find
    node *tmp = table[key];
    while (tmp != NULL)
    {
        if (strlen(tmp->word) == strlen(word))
        {
            int i, n;
            for (i = 0, n = strlen(word); i < n; i++)
            {
                if (tolower(tmp->word[i]) != tolower(word[i]))
                    break;
            }
            if (i == n)
                return true;
        }
        tmp = tmp->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isalpha(word[i]))
            sum += tolower(word[i]) - 'a';
        else
            sum += 27;
    }
    return sum;
    // return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // 打开dic
    FILE *f = fopen(dictionary, "r");
    if (f == NULL)
    {
        printf("fopen %s error.\n", dictionary);
        return false;
    }

    // 从dictionary中提取word
    char word[LENGTH + 1];
    memset(word, 0, LENGTH + 1);
    while (fgets(word, LENGTH + 2, f)) // 按行读取，同时\n也会读入
    {
        word[strlen(word) - 1] = '\0'; // 去除掉读入的\n
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("malloc node error!");
            return false;
        }
        strcpy(n->word, word);
        // 计算hash
        int key = hash(n->word);

        // 将word放入hash
        n->next = table[key];
        table[key] = n;
    }
    fclose(f);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int num = 0;
    for (int i = 0; i < N; i++)
    {
        node *tmp = table[i];
        while (tmp != NULL)
        {
            num++;
            tmp = tmp->next;
        }
    }
    return num;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i];
            table[i] = table[i]->next;
            free(tmp);
        }
    }
    return true;
}
