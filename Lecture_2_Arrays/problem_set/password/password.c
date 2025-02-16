// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and "
               "symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool lower_letter = false;
    bool upper_letter = false;
    bool number = false;
    bool symbol = false;
    for (int i = 0, n = strlen(password); i < n; i++)
    {
        if (isupper(password[i]))
        {
            upper_letter = true;
        }
        else if (islower(password[i]))
        {
            lower_letter = true;
        }
        else if (isdigit(password[i]))
        {
            number = true;
        }
        else
        {
            symbol = true;
        }
    }
    if (lower_letter && upper_letter && number && symbol)
    {
        return true;
    }
    return false;
}
