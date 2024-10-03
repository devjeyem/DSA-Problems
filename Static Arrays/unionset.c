#include <stdio.h>

int main() 
{
    int set1[100], set2[100], union_set[200];
    int size1, size2, i, j, k = 0;
    int found;

    // Input size and elements of the first set
    printf("Enter the number of elements in the first set: ");
    scanf("%d", &size1);
    printf("Enter the elements of the first set:\n");
    for (i = 0; i < size1; i++) 
    {
        scanf("%d", &set1[i]);
        union_set[k++] = set1[i];  // Add all elements of set1 to the union set
    }

    // Input size and elements of the second set
    printf("Enter the number of elements in the second set: ");
    scanf("%d", &size2);
    printf("Enter the elements of the second set:\n");
    for (i = 0; i < size2; i++) 
    {
        scanf("%d", &set2[i]);
    }

    // Add elements of set2 to union_set, only if they are not already present
    for (i = 0; i < size2; i++) 
    {
        found = 0;
        for (j = 0; j < size1; j++) 
        {
            if (set2[i] == set1[j]) 
            {
                found = 1;
                break;
            }
        }
        if (!found) 
        {
            union_set[k++] = set2[i];  // Add unique elements of set2 to union set
        }
    }

    // Output the union
    printf("Union of the two sets:\n");
    for (i = 0; i < k; i++) 
    {
        printf("%d ", union_set[i]);
    }
    printf("\n");

    return 0;
}
