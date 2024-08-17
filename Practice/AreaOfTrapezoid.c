#include <stdio.h>
#include <math.h>

int main()
{
    int base1,base2,height;
    double A;

    printf("Enter base 1: ");
    scanf("%d",&base1);

    printf("Enter base 2: ");
    scanf("%d",&base2);

    printf("Enter height: ");
    scanf("%d",&height);

    A = (1.0/2.0)*(base1+base2)*(height);
    printf("Area of triangle is %.2lf inches.",A);
}