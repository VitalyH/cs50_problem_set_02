#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Asking user for height and checking it's range
    int h, i, j;
    do
    {
        h = get_int("Height: ");
    }
    while (h <0 || h > 23);

    // Building the piramide
    for (i = 0; i < h; i++)
    {
        // Printing spaces
        for (j = 0; j < h - i - 1; j++)
        {
            printf(" ");
        }
        // Printing # - left row
        for (j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        // Printing two spaces between rows
        for (j = 0; j < 2; j++)
        {
            printf(" ");
        }
        // Printing # - right row
        for (j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        // New row
        printf("\n");
    }
}