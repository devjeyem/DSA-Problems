#include <stdio.h>
#include <stdlib.h>

int mergeSortedArray(int *a1, int *a2, int s1, int s2, int **res)
{
    *res = (int*)malloc(sizeof(int)*(s1+s2));
    int i = 0, j = 0, k = 0;
    while (1)
    {
        if (i == s1 && j == s2)
            break;
        else if (i < s1 && j < s2)
            (*res)[k++] = (a1[i] < a2[j]) ? a1[i++] : a2[j++];
        else if (i == s1)
            (*res)[k++] = a2[j++];
        else if (j == s2)
            (*res)[k++] = a1[i++];
        
    }
    return s1+s2;
}

// Example usage
int main()
{
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10, 12};
    int* merged;
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int totalSize = mergeSortedArray(arr1, arr2, size1, size2, &merged);
    
    printf("Array 1: ");
    for(int i = 0; i < size1; i++)
        printf("%d ", arr1[i]);
    
    printf("\nArray 2: ");
    for(int i = 0; i < size2; i++)
        printf("%d ", arr2[i]);
    
    printf("\nMerged array: ");
    for(int i = 0; i < totalSize; i++)
        printf("%d ", merged[i]);
    printf("\n");
    
    free(merged);  // Don't forget to free allocated memory
    return 0;
}