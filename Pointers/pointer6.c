#include <stdio.h>

int main()
{
    int iVal;
    char cVal;
    void *ptr;
    iVal = 50; cVal=97;
    ptr = &iVal;
    printf("%d %d\n", *(int*)ptr,sizeof(ptr));
    ptr = &cVal;
    printf("%c %d\n", *(char*)ptr,sizeof(ptr));
}