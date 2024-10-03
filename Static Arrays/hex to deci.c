#include <stdio.h>
#include <string.h>
#include <math.h>

int hexToDecimal(char *hex)
{
    int decimal = 0;
    int length = strlen(hex);
    
    // Traverse each digit of the hex string from right to left
    for (int i = 0; i < length; i++)
    {
        char c = hex[length - i - 1];
        int digit;

        // Convert character to its decimal equivalent
        if (c >= '0' && c <= '9')
        {
            digit = c - '0'; // Convert '0'-'9' to 0-9
        }
        else if (c >= 'A' && c <= 'F')
        {
            digit = c - 'A' + 10; // Convert 'A'-'F' to 10-15
        }
        else if (c >= 'a' && c <= 'f')
        {
            digit = c - 'a' + 10; // Convert 'a'-'f' to 10-15
        }
        else
        {
            printf("Invalid hexadecimal digit: %c\n", c);
            return -1; // Return an error value for invalid input
        }

        // Update the decimal value
        decimal += digit * pow(16, i);
    }

    return decimal;
}

int main()
{
    char hex[] = "2A3"; // Example hexadecimal number

    // Convert hex to decimal
    int decimal = hexToDecimal(hex);

    // Print the result
    if (decimal != -1) // Check for error
    {
        printf("Decimal representation of %s: %d\n", hex, decimal);
    }

    return 0;
}
