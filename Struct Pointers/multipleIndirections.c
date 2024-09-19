#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Allocate memory for 4 elements on the heap
    int ***x = (int ***)malloc(4 * sizeof(int **));

    // x[0] is an integer with value 3
    x[0] = (int **)malloc(sizeof(int *));
    *(x[0]) = (int *)malloc(sizeof(int));
    **(x[0]) = 3;

    // x[1] points to another heap with size 2
    x[1] = (int **)malloc(2 * sizeof(int *));
    x[1][0] = (int *)malloc(sizeof(int));
    *(x[1][0]) = 1;

    // x[1][1] points to another heap with size 5
    x[1][1] = (int *)malloc(5 * sizeof(int));
    x[1][1][0] = 4;

    // x[1][1][1] points back to x[1]
    x[1][1][1] = (int)x[1];

    // Allocate memory for another heap with size 8
    int *heap_of_8 = (int *)malloc(8 * sizeof(int));
    heap_of_8[0] = 7;
    for (int i = 1; i < 7; i++)
    {
        heap_of_8[i] = 0;
    }
    heap_of_8[7] = (int)x[1];

    // x[1][1][4] points to this heap of size 8
    x[1][1][4] = (int)heap_of_8;

    // x[2] is NULL
    x[2] = NULL;

    // x[3] points to another heap with size 6
    x[3] = (int **)malloc(6 * sizeof(int *));
    x[3][0] = (int *)malloc(sizeof(int));
    *(x[3][0]) = 5;

    // x[3][1-3] are NULL
    for (int i = 1; i < 4; i++)
    {
        x[3][i] = NULL;
    }

    // x[3][4] points to heap_of_8 (x[1][1][4])
    x[3][4] = (int *)heap_of_8;

    // x[3][5] is NULL
    x[3][5] = NULL;

    // Now, let's print the values by dereferencing x

    // x[0] value
    printf("x[0] = %d\n", **x[0]);

    // x[1][0] value
    printf("x[1][0] = %d\n", *x[1][0]);

    // x[1][1][0] value
    printf("x[1][1][0] = %d\n", x[1][1][0]);

    // x[1][1][1] points back to x[1]
    printf("x[1][1][1] points to x[1]\n");
    printf("x[1][1][1] = %d\n", *(int *)(x[1][1][1])); // Should print the value of x[1][0] which is 1

    // heap_of_8 values
    printf("heap_of_8[0] = %d\n", heap_of_8[0]);
    for (int i = 1; i < 7; i++)
    {
        printf("heap_of_8[%d] = %d\n", i, heap_of_8[i]); // Should print 0 for these elements
    }
    printf("heap_of_8[7] points to x[1] and its value is %d\n", *(int *)heap_of_8[7]);

    // x[2] is NULL
    if (x[2] == NULL)
    {
        printf("x[2] = NULL\n");
    }

    // x[3][0] value
    printf("x[3][0] = %d\n", *x[3][0]);

    // x[3][1-3] are NULL
    for (int i = 1; i < 4; i++)
    {
        if (x[3][i] == NULL)
        {
            printf("x[3][%d] = NULL\n", i);
        }
    }

    // x[3][4] points to heap_of_8
    printf("x[3][4][0] = %d\n", heap_of_8[0]);

    // x[3][5] is NULL
    if (x[3][5] == NULL)
    {
        printf("x[3][5] = NULL\n");
    }

    // Free allocated memory
    free(*(x[0]));
    free(x[0]);
    free(x[1][0]);
    free(x[1][1]);
    free(x[1]);
    free(x[3][0]);
    free(x[3]);
    free(heap_of_8);
    free(x);

    return 0;
}
