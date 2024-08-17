#include <stdio.h>
#include <math.h>

int main()
{
    int t = 4;
    double p =1800 ;
    double A;
    double r = 0.02;
    A = p* exp(r*t);
    printf("%.2lf " , A);
}