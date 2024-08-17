#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int jagged[5][5];

    for (int i=0;i<5;i++)
    {
        for (int j=0;j<5;j++)
        {
            if(i>=j)
            {
                jagged[i][j]=j;
            }
            else
            {
                jagged[i][j]=-1;
            }
        }
    }

    for (int i=0;i<5;i++)
    {
        printf("[%d] ", i);
        for (int j=0;j<5;j++)
        {
            if (jagged[i][j]==-1)
            {
                printf(" ");
            }
            else
            {
                printf("%d ", jagged[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n");
    //Swapping
    int temp;
    for (int i=0;i<5;i++)
    {
        temp=jagged[1][i];
        jagged[1][i] = jagged [4][i];
        jagged[4][i] = temp;
    }

    for(int i = 0; i< 5;i++)
    {
        printf("[%d] ", i);
        for (int j = 0;j<5;j++)
        {
            if(jagged[i][j]==-1)
            {
                printf(" ");
            }
            else
            {
                printf("%d ", jagged[i][j]);
            }
        }
        printf("\n");
    }
}
