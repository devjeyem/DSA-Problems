#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
long long powerMod(long long b, long long n, long long m)
{
    long long x = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            x = (x * b) % m;
        }
        b = (b * b) % m;
        n = n / 2;
    }
    return x;
}
// Function to calculate gcd of a and b
long long gcd(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}
// Function to find modular inverse using extended Euclidean algorithm
long long invMod(long long a, long long m)
{
    long long m0 = m;
    long long y = 0, x = 1;
    if (gcd(a, m) != 1)
    {
        printf("No modular inverse exists\n");
        return -1;
    }
    long long q, t;
    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}
void encryption(long long e, long long n, long long *ciphertext, int blocks, int digits) 
{
    printf("Enter Blocks of Plaintext: ");
    for (int i = 0; i < blocks; i++) 
    {
        long long plaintext;
        scanf("%lld", &plaintext);
        ciphertext[i] = powerMod(plaintext, e, n);
    }
}
// FLAG will serve as the indicator of errors in function main
// d is the private key exponent to decrypt the message
void decryption(long long phi, long long e, long long n, long long *d, int *flag)
{
    if(gcd(phi, e) > 1)
    {
        *flag = 1;
        return;
    }
    *d = invMod(e, phi);
    int blocks;
    printf("\nHow many blocks of encrypted code: ");
    scanf("%d", &blocks); 
    int digits;
    printf("How many digits per block: ");
    scanf("%d", &digits);
    long long *ciphertext = (long long*)malloc(sizeof(long long)*blocks);
    printf("Enter Blocks of Ciphertext: ");
    for(int i=0; i < blocks; i++)
        scanf("%lld", &ciphertext[i]);
    long long *decrypted_code = (long long*)malloc(sizeof(long long)*blocks);
    printf("\n===========================================\n");
    printf("Decrypted Code: ");
    for(int i=0; i<blocks; i++)
    {
        decrypted_code[i] = powerMod(ciphertext[i], *d, n);
        printf("%lld ", decrypted_code[i]);
    }
    // Translate the decrypted numbers to letters
    printf("\nDecrypted Message: ");
    for (int i = 0; i < blocks; i++) 
    {
        long long decrypted_block = decrypted_code[i];
        int temp_digit = digits;
        int divisor = pow(10, temp_digit-2);
        while (divisor > 0) 
        {
            long long temp = decrypted_block / divisor;
            if (temp >=0 && temp < 26) 
            {
                int letter = 'A' + (temp); 
                printf("%c", letter);
            } 
            decrypted_block %= divisor;
            divisor /= 100;
        }
    }
    printf("\n===========================================\n");
    printf("\n");
    free(ciphertext);
    free(decrypted_code);
}
int main()
{
    printf("[E]ncrypt  [D]ecrypt\n>> ");
    char input;
    scanf(" %c", &input);
    long long p, q;
    long long n, phi;
    long long e, d;
    printf("\nEnter value for (p) and (q): ");
    scanf("%lld %lld", &p, &q);
    printf("Enter value for (e): ");
    scanf("%lld", &e);
    phi = (p-1) * (q-1);
    n = p * q;
    switch(toupper(input))
    {
         case 'E': 
            {
                int blocks;
                printf("How many blocks of plaintext: ");
                scanf("%d", &blocks);
                int digits;
                printf("How many digits each block: ");
                scanf("%d", &digits);
                long long *ciphertext = (long long*)malloc(sizeof(long long)*blocks);
                encryption(e, n, ciphertext, blocks, digits);
                printf("Ciphertext: ");
                for (int i = 0; i < blocks; i++)
                    printf("%lld ", ciphertext[i]);
                printf("\n");
                free(ciphertext);
                break;
            }
        case 'D':
        {
            int flag_d = 0;
            decryption(phi, e, n, &d, &flag_d);
            if(flag_d)
            {
                printf("Modular inverse does not exists. (e) must be relatively prime with (phi).\n");
                return 1;
            }
        }    
    }
    return 0;
}