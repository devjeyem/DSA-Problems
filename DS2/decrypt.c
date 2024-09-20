#include <stdio.h>

int main() {
    int base, exponent, modulus;

    printf("Enter the base: ");
    scanf("%d", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    printf("Enter the modulus: ");
    scanf("%d", &modulus);

    int x, y;
    int gcd = 0;

    // Calculate GCD using Extended Euclidean Algorithm
    int a = base;
    int b = modulus;
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
        if (a != 0) {
            temp = y;
            y = x - (a / b) * y;
            x = temp;
        }
    }
    gcd = a;
    x = (x % modulus + modulus) % modulus;

    // Check if modular inverse exists
    if (gcd != 1) {
        printf("Modular inverse does not exist.\n");
        return 0;
    }

    // Calculate inverse modular exponentiation
    int result = 1;
    int inverse = x;
    for (int i = 0; i < exponent; i++) {
        result = (result * inverse) % modulus;
    }

    printf("Inverse modular exponentiation result: %d\n", result);

    return 0;
}