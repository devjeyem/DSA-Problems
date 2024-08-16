#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; 
    printf("Enter a number: ");
    scanf("%d", &n);

    int *num = (int*)malloc(sizeof(int)*n);

    for (int i = 0 ; i<n; i++)
    {
        scanf("%d",&num[i]);
    }

    for (int i = 0;i<n;i++)
    {
        if (num[i]%3 == 0)
        {
            printf("%d, ",num[i]);
        }
    }

    free(num);
    num = NULL;

}