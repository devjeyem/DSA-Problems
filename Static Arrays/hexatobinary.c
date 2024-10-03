#include <stdio.h>
#include <string.h>
#include <math.h>

int binaryToDecimal(char *binary)
{
    int decimal = 0;
    int length = strlen(binary);
    
    // Traverse each bit of the binary string from right to left
    for (int i = 0; i < length; i++)
    {
        // Convert character to integer (0 or 1)
        int bit = binary[length - i - 1] - '0';
        
        // Update the decimal value by adding the current bit value
        decimal += bit * pow(2, i);
    }

    return decimal;
}

int main()
{
    char binary[] = "1100100"; // Example binary number

    // Convert binary to decimal
    int decimal = binaryToDecimal(binary);

    // Print the result
    printf("Decimal representation of %s: %d\n", binary, decimal);

    return 0;
}
