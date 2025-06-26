#include <stdio.h>
#include <stdlib.h>

// Add prototypes here:
void ex1(void);
void ex2(void);

int main(void)
{
    ex3();
    return 0;
}

void ex1(void)
{
    char ch = 10;
    void *ptr = &ch;
    printf("%d, %d\n", *(char*)ptr, ++(*(char*)ptr)); // Undefined behavior
}

void ex2(void)
{
    char ch = 10;
    void *ptr = &ch;
    printf("%d\n", *(char*)ptr);
    ++(*(char*)ptr);
    printf("%d\n", *(char*)ptr);
}

void ex3(void)
{
    char ch = 10;
    void *ptr = &ch;
    printf("%d\n", *(char*)ptr);
    ++(*(char*)ptr);
    printf("%d\n", *(char*)ptr);
}


