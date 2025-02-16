#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int score_array[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                       1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int get_score(string word);

int main(void)
{
    // Prompt the user for two words
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    // Compute the score of each word
    int score1 = get_score(player1);
    int score2 = get_score(player2);
    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int get_score(string word)
{
    int len = strlen(word);
    int score = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(word[i]))
        {
            score += score_array[toupper(word[i]) - 'A'];
        }
    }
    return score;
}
