#include <stdio.h>

int main() {
    int arr[12] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60};
    int *p = arr + 6; // Initialize p to point to the element at index 6 (value 35)

    // Step 1
    int a = *(p++) + p[-2] + --p[1];

    // Step 2
    int b = p[-3] + *(--p) + p[3]--;

    // Step 3
    int c = *p-- + p[-2] + ++p[2];

    // Step 4
    int d = p[1] + ++p[-1] + *(p--);

    // Step 5
    int e = *(++p) + p[-2] + --p[2];

    // Step 6
    int f = *(p--) + --p[2] + p[-3];

    // Step 7
    int g = p[-1] + *(++p) + p[0]++;

    // Step 8
    int h = ++p[-3] + p[2]-- + *p--;

    // Step 9
    int i = p[3] + p[-2] + ++p[1];

    // Step 10
    int j = *(p++) + p[-3] + --p[2];

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %d\n", d);
    printf("e = %d\n", e);
    printf("f = %d\n", f);
    printf("g = %d\n", g);
    printf("h = %d\n", h);
    printf("i = %d\n", i);
    printf("j = %d\n", j);

    return 0;
}
