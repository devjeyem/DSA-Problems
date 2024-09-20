#include <stdio.h>

// Function to calculate the greatest common divisor (GCD) using Euclidean Algorithm
int gcd(int a, int b) 
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// Function to calculate the modular inverse using Extended Euclidean Algorithm
int modInverse(int a, int m) 
{
    int m0 = m;
    int y = 0, x = 1;

    if (gcd(a, m) != 1) 
    {
        printf("Modular inverse does not exist\n");
        return -1;
    }

    while (a > 1) 
    {
        int q = a / m;
        int t = m;

        m = a % m;
        a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x = x + m0;

    return x;
}

int main() {
    int d = modInverse(13, 2436);
    printf("Modular inverse of 13 modulo 2436 is %d\n", d);
    return 0;
}
