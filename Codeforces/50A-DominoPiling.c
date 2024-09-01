#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int area = m * n;
    int dominos = area / 2;
    printf("%d\n", dominos);
}