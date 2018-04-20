#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check how many comand line arguments provided
    // if 0 or more than 1 - exit
    if (argc != 2)
    {
        printf("Error!\n");
        return 1;
    }

    // Gain access to cipher key provided by user
    // Cast it (string) in int
    int key = atoi(argv[1]);

    // Ask user for a text
    string plaintext = get_string("plaintext: ");

    // Start printing output
    printf("ciphertext: ");

    // Execute cipher
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Check if char is letter
        if (isalpha(plaintext[i]))
        {
            // Check if letter is uppercase or lowercase
            // Then convert
            if islower(plaintext[i])
            {
                printf("%c", (((plaintext[i] + key) - 'a') % 26) + 'a');
            }
            else if isupper(plaintext[i])
            {
                printf("%c", (((plaintext[i] + key) - 'A') % 26) + 'A');
            }
        }
        // If not print right away
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}