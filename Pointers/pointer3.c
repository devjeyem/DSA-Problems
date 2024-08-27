#include <stdlib.h>
#include <stdio.h>

int *input();

int main()
{
    int sum = 0;
    int *ptr1 = input();
    for (int i = 0;i<5;i++)
        sum = sum + *(ptr1+i);
    printf("Sum is %d", sum);
    free(ptr1);
    ptr1 = NULL;
}

int *input()
{
    int *ptr;
    ptr = (int*)malloc(5*sizeof(int));
    printf("Enter 5 numbers: ");
    for (int i = 0; i<5; i++)
        scanf("%d", ptr + i);

    return ptr;
}