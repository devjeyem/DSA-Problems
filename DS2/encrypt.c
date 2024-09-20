#include <stdio.h>

// Function to calculate (b^n) % m
long long powerMod(long long b, long long n, long long m) {
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) 
        {
            res = (res * b) % m;
        }
        b = (b * b) % m;
        n = n / 2;
    }
    return res;
}

int main() {
    long long b, n, m;
    printf("Enter base (b): ");
    scanf("%lld", &b);
    printf("Enter exponent (n): ");
    scanf("%lld", &n);
    printf("Enter modulus (m): ");
    scanf("%lld", &m);
    long long result = powerMod(b, n, m);
    printf("%lld^%lld mod %lld = %lld\n", b, n, m, result);
    return 0;
}