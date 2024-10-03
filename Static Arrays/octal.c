#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *decimalToOctal(int n, int *len)
{
    *len = 0;
    int temp = n;
    while (temp != 0)
    {
        temp = temp/8;
        (*len)++;
    }

    int *octal = (int*)malloc(sizeof(int)*(*len+1));
    octal[0]=*len;
    int i = *len;
    do{
        octal[i] = n%8;
        n /= 8;
    }while(--i);

    return octal;
}

int main()
{
    int len = 0;
    int *result = decimalToOctal(1008, &len);
    for (int i = 0; i < len; i++)
    {
        printf("%d", result[i]);
    }
}