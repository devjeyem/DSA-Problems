#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a;
    int *p;
    int **q;

    a = 14;
    p = &a;
    q = &p;

    printf("%d\n", a);
    printf("%d\n", *p);
    printf("%d\n", **q);
    printf("%p\n", &a);    
    printf("%p\n", p);

    printf("%p\n", &p);
    printf("%p\n", q);

    printf("%p\n", &q);

    return 0;
}