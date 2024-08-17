#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);

int main()
{
    for (int i = 100; i<1000;i++)
    {
        if(isPrime(i))
            printf("%d ", i);
    }
}

bool isPrime(int n)
{
    if (n<2)
        return 0;
    for (int i = 2; i*i<=n;i++)
        if(n%i==0)
            return 0;
    return 1;
}