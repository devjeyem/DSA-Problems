#include <stdio.h>

int main()
{
    long long n,m,a;
    scanf("%lld %lld %lld",&n,&m,&a);

    long long  flagstonesInN = (n+a-1)/a;
    long long flagstonesInM = (m+a-1)/a;
    long long  flagstonesInNM = flagstonesInN*flagstonesInM;
    printf("%lld\n",flagstonesInNM);
}