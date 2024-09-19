#include <stdio.h>
#include <stdlib.h>

int main() {
    int **x = (int**)malloc(4 * sizeof(int*)); 

    *x = (int*)malloc(sizeof(int));
    **x = 3; 
    printf("%d\n", **x);

    // Allocate memory for a POINTER to an integer at the second element
    *(x + 1) = (int*)malloc(sizeof(int)); 

    // Assign a value to the integer POINTED to by the second element
    *(*(x + 1)) = 5;

    // Print the value of the integer pointed to
    printf("%d\n", *(*(x + 1)));

    // Free the allocated memory
    free(*x);         // Free the integer first
    free(*(x + 1));   // Free the second integer
    free(x);          // Then free the main array

    return 0;
}