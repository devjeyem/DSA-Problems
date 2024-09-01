#include <stdio.h>

int main() {
    char str[101];
    int count[4] = {0}; // count[1], count[2], count[3]

    // Read the input string
    scanf("%s", str);

    // Count the occurrences of each number
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] >= '1' && str[i] <= '3') 
        {
            count[str[i] - '0']++;
        }
    }

    // Print the numbers in non-decreasing order
    int first = 1;
    for (int i = 1; i <= 3; i++) 
    {
        for (int j = 0; j < count[i]; j++) 
        {
            if (!first) 
            {
                printf("+");
            }
            printf("%d", i);
            first = 0;
        }
    }

    printf("\n");
    return 0;
}