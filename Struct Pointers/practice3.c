#include <stdio.h>
#include <stdlib.h>

struct IntArray {
    int *array;
    int size;
};

// Function to initialize the struct
void initArray(struct IntArray *arr, int size) {
    arr->size = size;
    arr->array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr->array[i] = i + 1;  // Initialize with values 1, 2, 3, ...
    }
}

// Function to print the elements of the array
void printArray(struct IntArray *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->array[i]);
    }
    printf("\n");
}

// Function to free the allocated memory
void freeArray(struct IntArray *arr) {
    free(arr->array);
    arr->array = NULL;
}

int main() {
    struct IntArray myArray;

    // Initialize the array with 5 elements
    initArray(&myArray, 5);

    // Print the array elements
    printArray(&myArray);

    // Free the allocated memory
    freeArray(&myArray);

    return 0;
}
