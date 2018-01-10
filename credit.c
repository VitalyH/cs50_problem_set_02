#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long number, checkNumber;
    int count, i, everySecondNumber, checksum, checksumNow, everyFirstNumber, valid, masterCheck, visaCheck, amexCheck;
    bool ccNotFound = true;


    // Asking user for card number which is > 0
    do
    {
        number = get_long_long("Number: ");
    }
    while (number <= 0);

    // Counting digits in number
    checkNumber = number;
    while (checkNumber > 0)
        {
            checkNumber = checkNumber / 10;
            count = count + 1;
        }

    // Checking lenght, if not 13, 15 or 16 - instant INVALID
    if (count < 13 || count > 16 || count == 14)
        {
            printf("INVALID\n");
        }

    // Main calculations
    if (count == 13 || count == 15 || count == 16)
        {

            for (i = 0; i < 8; i++) // Runnung it eight times
            {
                everyFirstNumber = number % 10;             // Extracting every first digit from the end
                everySecondNumber = (number / 10) % 10;     // Extracting every second digit from the end
                number /= 100;                              // Card number losing two last digits

                checksumNow = everySecondNumber * 2;        // First step of checksum calculation - *2
                if (checksumNow > 9)                        // Checking if result more then one digit
                    {
                    checksumNow =
                        ((checksumNow / 10) % 10) + (checksumNow % 10); // Addition of the first and second digits
                    }

                // Checking company identifiers
                if (number >= 4 && number <= 999)
                    {
                    amexCheck = (number / 10);              // American Express: 15, should start from 34 or 37
                    masterCheck = number;                   // Master Card: 16, should start from 51, 52, 53, 54 or 55
                    if (count == 16)
                    {
                        visaCheck = (number / 10) % 10;         // Visa: 16...
                    } else {
                        visaCheck = number % 10;                // ..or 13, should start from 4
                    }}

                // Checksum total calculation
                checksum = checksum + checksumNow + everyFirstNumber;

            }

            // Validating and printing result
            valid = checksum % 10;      // Should be zero
            if (valid == 0 && amexCheck == 37) // Checks for American Express
                {
                    printf("AMEX\n");
                    ccNotFound = false;
                }
            if (valid == 0 && masterCheck >= 51 && masterCheck <= 55) // Checks for Master
                {
                    printf("MASTERCARD\n");
                    ccNotFound = false;
                }
            if (valid == 0 && visaCheck == 4)               // Checks for Visa
                {
                    printf("VISA\n");
                    ccNotFound = false;
                }
            if (ccNotFound == true)                         // If all checks failed
                {
                printf("INVALID\n");
                }
        }
    return 0;
}