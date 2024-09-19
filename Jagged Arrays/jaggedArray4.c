#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int isPrime(int x)
{
    int limit = (int)sqrt(x)+1;
    for(int i = 2; i< limit; i++)
        if (x%i==0)
            return 0;
    return 1;
}

int main()
{
    system("cls");
    int len[7] = {9,0,3,2,0,2,4};
    int **arr_spec = (int**)malloc(sizeof(int*)*7);

    for (int i = 0; i<7 ; i++)
    {
        arr_spec[i] = (int*) malloc(sizeof(int)*len[i]);
    }
    arr_spec[1] = arr_spec[4] = NULL;

    int ctr = 0, n = 2;
    while (ctr<len[0])
    {
        if(isPrime(n))
        {
            arr_spec[0][ctr++] = n;
        }
        n++;
    }


    for (int j = 0; j<len[0]; j++)
    {
        printf("%d " , arr_spec[0][j]);
    }
    printf("\n");

    int num = 30;
    for (int i = 0; i<len[2]; i++)
    {
        arr_spec[2][i] = num;
        num += 30;
    }

    for (int j = 0; j<len[2]; j++)
    {
        printf("%d " , arr_spec[2][j]);
    }
    printf("\n");

    int a = 100;
    for (int i = 0; i<len[3] ; i++)
    {
        arr_spec[3][i] = a;
        a += 100;
    }

    for (int j = 0; j<len[3]; j++)
    {
        printf("%d " , arr_spec[3][j]);
    }
    printf("\n");

    int b = 77;
    for (int i = 0; i<len[5] ; i++)
    {
        arr_spec[5][i] = b;
        b += 700;
    }

    for (int j = 0; j<len[5]; j++)
    {
        printf("%d " , arr_spec[5][j]);
    }
    printf("\n");

    int c = 2;
    for (int i = 0; i<len[6]; i++)
    {
        arr_spec[6][i] = c;
        c += 2;
    }

    for (int j = 0; j<len[6]; j++)
    {
        printf("%d " , arr_spec[6][j]);
    }
    printf("\n");
    

    

}