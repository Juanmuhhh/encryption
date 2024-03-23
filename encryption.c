#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char rotate(char c, int n);

int main(int argc, string argv[])
{
    // If user inputs more than one command line argument, redirect user with message
    if (argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //If no argv[1] print out example
    if (argv[1] == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Get Key (number to shift by)
    string k = argv[1];

    //converts key to int
    int x = atoi(k);

    //// If Key is negative number, redirect user with message
    if (x < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // If argv[1] is not a number, rempromt user with an example
    for (int i = 0, n = strlen(k); i < n; i++)
    {
        while (isdigit(k[i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    string s = get_string("Plaintext: ");
    printf("Ciphertext: ");

    for (int j = 0, t = strlen(s); j < t; j++)
    {
        char z = rotate(s[j], x);
        printf("%c", z);
    }
    printf("\n");
}

char rotate(char c, int n)
{
    if (isupper(c))
    {
        c = (((c - 65) + n) % 26 + 65);
    }
    else if (islower(c))
    {
        c = (((c - 97) + n) % 26 + 97);
    }
    return c;
}
