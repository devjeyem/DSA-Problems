#include <stdio.h>
#include <stdlib.h>

char *decimalToHexa(int n, int *len)
{
    *len = 0;
    int temp = n;
    while (temp != 0)
    {
        temp /= 16;
        (*len)++;
    }

    char *hexa = (char*)malloc(sizeof(char)*(*len+1));
    hexa[*len]= '\0';
    
    for  (int i = *len-1; i >= 0; i--)
    {
        int rem=n%16;
        if(rem<16)
            hexa[i] = rem + '0';
        else
            hexa[i] = rem - 10 + 'A';
        n /= 16;
    }

    return  hexa;


}

int main()
{
    int len = 0;
    int number = 1008; // Example decimal number
    char *result = decimalToHexa(number, &len);

    // Print the hexadecimal result
    printf("Hexadecimal representation of %d: %s\n", number, result);

    // Free the allocated memory
    free(result);
}