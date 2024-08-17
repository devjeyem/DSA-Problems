#include <stdio.h>
#include <math.h>


int main ()
{

    int i,j;
    int isPrime;
    for (i = 100; i<= 1000;i++)
    {
        isPrime = 1;
        for (j = 2; j*j<=i; j++)
        {
            if (i%j==0)
                isPrime = 0; // false
                break;
        }
        if(isPrime)
            printf("%d ", i);
    }
}