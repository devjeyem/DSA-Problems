#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert hexadecimal to decimal
int hexToDecimal(char *hex)
{
    int decimal = 0;
    int length = strlen(hex);

    for (int i = 0; i < length; i++)
    {
        char digit = hex[length - i - 1];
        if (digit >= '0' && digit <= '9')
            decimal += (digit - '0') * pow(16, i);  // '0'-'9' to 0-9
        else if (digit >= 'A' && digit <= 'F')
            decimal += (digit - 'A' + 10) * pow(16, i);  // 'A'-'F' to 10-15
        else if (digit >= 'a' && digit <= 'f')
            decimal += (digit - 'a' + 10) * pow(16, i);  // Lowercase hex digits
    }

    return decimal;
}

// Function to convert decimal to hexadecimal (returns string)
char* decimalToHex(int n)
{
    char *hex = (char*)malloc(33); // 32 characters max + null terminator
    hex[32] = '\0';  // Null-terminate the string

    for (int i = 31; i >= 0; i--)
    {
        int remainder = n % 16;
        if (remainder < 10)
            hex[i] = remainder + '0';  // Convert 0-9
        else
            hex[i] = remainder - 10 + 'A';  // Convert 10-15 to 'A'-'F'
        n /= 16;
    }

    // Find the first non-zero digit for correct display
    char *firstNonZero = hex;
    while (*firstNonZero == '0') firstNonZero++;

    return firstNonZero;
}

int main()
{
    char hex1[33], hex2[33];

    // Input two hexadecimal numbers
    printf("Enter first hexadecimal number: ");
    scanf("%32s", hex1);  // Read up to 32 characters

    printf("Enter second hexadecimal number: ");
    scanf("%32s", hex2);  // Read up to 32 characters

    // Convert both hexadecimal numbers to decimal
    int decimal1 = hexToDecimal(hex1);
    int decimal2 = hexToDecimal(hex2);

    // Add the decimal values
    int decimalSum = decimal1 + decimal2;

    // Convert the sum back to hexadecimal
    char *hexSum = decimalToHex(decimalSum);

    // Print the result
    printf("Sum of %s and %s in hexadecimal is: %s\n", hex1, hex2, hexSum);

    // Free the allocated memory (this is correct now)
    free(hexSum);

    return 0;
}
