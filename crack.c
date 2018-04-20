#include <stdio.h>
#include <string.h>
#define _XOPEN_SOURCE
#include <unistd.h>

char *crypt(const char *key, const char *salt);

int main(int argc, char *argv[])
{
    // Check correctness of the user input
    if (argc != 2)
    {
        printf("Error! Try: ./crack hash\n");
        return 1;
    }

    // Variables
    const char *hash_given = argv[1];    // Hash given by user
    const char *hashed_word = NULL;      // Our hash by default
    const char *salt = "50";             // Salt given
    char word[5];                        // Our possible password
    // All possible simbols in the password
    char *letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n = strlen(letters);             // Number of symbols in the *letters

    // Check a-Z
    for (int x = 0; x < 52; x++)
    {
        // Iterate through letters
        word[0] = letters[x];
        // Crypt every char (there) / combination (later)
        hashed_word = crypt(word, salt);
        // Compare given hash and our new hash
        if (strcmp(hashed_word, hash_given) == 0)
        {
            // If they match - password found!
            goto PRINT;
        }
    }

    // Check aa-ZZ
    for (int x = 0; x < n; x++)
    {
        word[0] = letters[x];
        hashed_word = crypt(word, salt);
        if (strcmp(hashed_word, hash_given) == 0)
        {
            goto PRINT;
        }

        for (int y = 0; y < n; y++)
        {
            word[1] = letters[y];
            hashed_word = crypt(word, salt);
            if (strcmp(hashed_word, hash_given) == 0)
            {
                goto PRINT;
            }
        }
    }

    // Check aaa-ZZZ
    for (int x = 0; x < n; x++)
    {
        word[0] = letters[x];
        hashed_word = crypt(word, salt);
        if (strcmp(hashed_word, hash_given) == 0)
        {
            goto PRINT;
        }

        for (int y = 0; y < n; y++)
        {
            word[1] = letters[y];
            hashed_word = crypt(word, salt);

            if (strcmp(hashed_word, hash_given) == 0)
            {
                goto PRINT;
            }

            for (int z = 0; z < n; z++)
            {
                word[2] = letters[z];
                hashed_word = crypt(word, salt);
                if (strcmp(hashed_word, hash_given) == 0)
                {
                    goto PRINT;
                }
            }
        }
    }

    // Check aaaa-ZZZZ
    for (int x = 0; x < n; x++)
    {
        word[0] = letters[x];
        hashed_word = crypt(word, salt);
        if (strcmp(hashed_word, hash_given) == 0)
        {
            goto PRINT;
        }

        for (int y = 0; y < n; y++)
        {
            word[1] = letters[y];
            hashed_word = crypt(word, salt);
            if (strcmp(hashed_word, hash_given) == 0)
            {
                goto PRINT;
            }

            for (int z = 0; z < n; z++)
            {
                word[2] = letters[z];
                hashed_word = crypt(word, salt);

                if (strcmp(hashed_word, hash_given) == 0)
                {
                    goto PRINT;
                }

                for (int t = 0; t < n; t++)
                {
                    word[3] = letters[t];
                    hashed_word = crypt(word, salt);
                    if (strcmp(hashed_word, hash_given) == 0)
                    {
                        goto PRINT;
                    }
                }
            }
        }
    }

    // Check aaaaa-ZZZZZ
    for (int x = 0; x < n; x++)
    {
        word[0] = letters[x];
        hashed_word = crypt(word, salt);
        if (strcmp(hashed_word, hash_given) == 0)
        {
            goto PRINT;
        }

        for (int y = 0; y < n; y++)
        {
            word[1] = letters[y];
            hashed_word = crypt(word, salt);
            if (strcmp(hashed_word, hash_given) == 0)
            {
                goto PRINT;
            }

            for (int z = 0; z < n; z++)
            {
                word[2] = letters[z];
                hashed_word = crypt(word, salt);
                if (strcmp(hashed_word, hash_given) == 0)
                {
                    goto PRINT;
                }

                for (int t = 0; t < n; t++)
                {
                    word[3] = letters[t];
                    hashed_word = crypt(word, salt);
                    if (strcmp(hashed_word, hash_given) == 0)
                    {
                        goto PRINT;
                    }

                    for (int w = 0; w < n; w++)
                    {
                        word[4] = letters[t];
                        hashed_word = crypt(word, salt);
                        if (strcmp(hashed_word, hash_given) == 0)
                        {
                            goto PRINT;
                        }
                    }
                }
            }
        }
    }
PRINT:
    printf("%s\n", word);

    return 0;
}