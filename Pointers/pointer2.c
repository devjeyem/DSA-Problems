#include <stdio.h>

// Function declaration with pointers for min and max
void minMax(int arr[], int len, int *min, int *max);

int main()
{
    int a[] = {23, 9, 2, 33, 44};
    int min, max;
    int len = sizeof(a) / sizeof(a[0]);
    
    // Call minMax function passing addresses of min and max
    minMax(a, len, &min, &max);
    
    // Print the result
    printf("%d , %d\n", min, max);
        return 0;
}

void minMax(int arr[], int len, int *min, int *max)
{
    *min = *max = arr[0];  // Initialize min and max

    for (int i = 1; i < len; i++)
    {
        if (arr[i] > *max)
            *max = arr[i];
        if (arr[i] < *min)
            *min = arr[i];
    }
}
