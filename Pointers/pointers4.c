#include <stdio.h>

int main() 
{
    int arr[15] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30};
    int *p = arr + 10; // Initialize p to point to the element at index 10

    // Step 1
    int a = --p[2] + ++p[-5]; // What is the value of 'a'?

    // Step 2
    int b = p[-7]-- + p[3]; // What is the value of 'b'?

    // Step 3
    int c = ++p[-3] + p[4]--; // What is the value of 'c'? What does p[4] become after this operation?

    // Step 4
    int d = --p[1] + p[-8]++; // What is the value of 'd'? What does p[-8] become after this operation?

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %d\n", d);
    
    for (int i = 0; i< 15; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
