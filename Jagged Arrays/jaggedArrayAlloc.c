#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define the sizes for each row of the jagged array
    int row_sizes[5] = {1, 2, 3, 4, 5};
    
    // Create the jagged array
    int **jagged = (int **)malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++) 
    {
        jagged[i] = (int *)malloc(row_sizes[i] * sizeof(int));
    }

    // Initialize the jagged array
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < row_sizes[i]; j++) {
            jagged[i][j] = j;
        }
    }

    // Print the jagged array before swapping
    printf("Before swapping:\n");
    for (int i = 0; i < 5; i++) {
        printf("[%d] ", i);
        for (int j = 0; j < row_sizes[i]; j++) {
            printf("%d ", jagged[i][j]);
        }
        printf("\n");
    }

    // Swap rows 1 and 4 carefully
    // Note: Ensure that both rows have the same size before swapping
    int temp_size = row_sizes[1];
    if (temp_size != row_sizes[4]) {
        printf("Rows have different sizes, cannot swap directly.\n");
    } else {
        int *temp = jagged[1];
        jagged[1] = jagged[4];
        jagged[4] = temp;
    }

    // Print the jagged array after swapping
    printf("\nAfter swapping:\n");
    for (int i = 0; i < 5; i++) {
        printf("[%d] ", i);
        for (int j = 0; j < row_sizes[i]; j++) {
            printf("%d ", jagged[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < 5; i++) {
        free(jagged[i]);
    }
    free(jagged);

    return 0;
}
