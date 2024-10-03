#include <stdio.h>
#include <string.h>
#include <math.h>

int octalToDecimal(char *octal)
{
    int decimal = 0;
    int length = strlen(octal);
    
    // Traverse each digit of the octal string from right to left
    for (int i = 0; i < length; i++)
    {
        // Convert character to integer (0 to 7)
        int digit = octal[length - i - 1] - '0';
        
        // Update the decimal value by adding the current digit value
        decimal += digit * pow(8, i);
    }

    return decimal;
}

int main()
{
    char octal[] = "145"; // Example octal number

    // Convert octal to decimal
    int decimal = octalToDecimal(octal);

    // Print the result
    printf("Decimal representation of %s: %d\n", octal, decimal);

    return 0;
}
