#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *decimalToBinary(int n, int *len) 
{
    *len = 0;
    int temp = n;
    while(temp != 0)
    {
        temp = temp / 2;
        (*len)++;
    }
    int *binary = (int*)malloc(sizeof(int)*((*len)+1));
    binary[0]= *len;
    int i = *len;
    do{
        binary[i]= n % 2;
        n /= 2;
    }while (i--);

    return binary;
}

int main()
{
    int len = 0;
    int *result = decimalToBinary(10, &len);
    for (int i = 0; i < len; i++)
    {
        printf("%d", result[i]);
    }

}