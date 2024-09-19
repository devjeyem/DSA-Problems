#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len[5] = {1, 2, 3, 4, 5};

    // Allocate jagged array (array of pointers)
    int **jaggedArray = (int**)malloc(sizeof(int*) * 5);

    for (int i = 0; i < 5; i++)
    {
        jaggedArray[i] = (int*)malloc(sizeof(int) * len[i]);
    }

    // Initialize the jagged array
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < len[i]; j++)
        {
            jaggedArray[i][j] = j;
        }
    }

    // Print the jagged array before swapping
    printf("Before swapping rows 2 and 5:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("[%d]", i);
        for (int j = 0; j < len[i]; j++)
        {
            printf(" %d", jaggedArray[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Swap the pointers to rows 2 and 5
    int *tempRow = jaggedArray[1]; // Row 2 (index 1)
    jaggedArray[1] = jaggedArray[4]; // Row 5 (index 4)
    jaggedArray[4] = tempRow;

    // Swap the lengths of row 2 and row 5 in len[]
    int tempLen = len[1]; // Length of row 2
    len[1] = len[4]; // Length of row 5
    len[4] = tempLen;

    // Print the jagged array after swapping
    printf("After swapping rows 2 and 5:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("[%d]", i);
        for (int j = 0; j < len[i]; j++)
        {
            printf(" %d", jaggedArray[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < 5; i++)
    {
        free(jaggedArray[i]);
    }
    free(jaggedArray);

    return 0;
}
 