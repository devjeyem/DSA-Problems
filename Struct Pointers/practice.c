#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Allocate memory for 4 elements on the heap
    int **x = (int **)malloc(4 * sizeof(int *));
    
    // x[0] is an integer with value 1
    x[0] = (int *)malloc(sizeof(int));
    *x[0] = 1;
    
    // x[1] points to another heap with size 2
    x[1] = (int *)malloc(2 * sizeof(int));
    x[1][0] = 10; // example value
    x[1][1] = 20; // example value
    
    // x[2] is NULL
    x[2] = NULL;
    
    // x[3] points to another heap with size 6
    x[3] = (int *)malloc(6 * sizeof(int));
    for (int i = 0; i < 6; i++)
    {
        x[3][i] = i * 10; // example values
    }
    
    // Example: Accessing and printing values
    printf("x[0] = %d\n", *x[0]);
    printf("x[1][0] = %d, x[1][1] = %d\n", x[1][0], x[1][1]);
    printf("x[2] = %p\n", x[2]);
    printf("x[3]: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", x[3][i]);
    }
    printf("\n");

    // Free allocated memory
    free(x[0]);
    free(x[1]);
    free(x[3]);
    free(x);

    return 0;
}
