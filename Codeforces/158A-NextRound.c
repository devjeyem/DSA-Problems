#include <stdio.h>

int main ()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int ctr = 0;
    int a[50];
    for  (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int threshold = a[k - 1];
    for (int i  = 0; i < n; i++)
    {
        if (a[i] >= threshold && a[i] > 0)
        {
            ctr++;
        }
    }
    printf("%d\n", ctr);
}