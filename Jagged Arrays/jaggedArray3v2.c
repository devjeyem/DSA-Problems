#include <stdio.h>

int main() {
    int jagged[5][5]; //BigO(n)

    // Initialize the array
    for (int k = 0; k < 25; k++)
    {
        int i = k / 5;
        int j = k % 5;
        if (i >= j) 
        {
            jagged[i][j] = j;
        } 
        else 
        {
            jagged[i][j] = -1;
        }
    }

    // Print the array
    for (int k = 0; k < 25; k++) 
    {
        int i = k / 5;
        int j = k % 5;
        if (k%5==0)
        {
            printf("[%d] ", i); 
        }
        if (jagged[i][j] == -1) 
        {
            printf(" ");
        } 
        else 
        {
            printf("%d ", jagged[i][j]);
        }
        if (j == 4) 
        {
            printf("\n");
        }
        
    }

    printf("\nAfter swap: \n");
    int temp;
    for (int i=0;i<5;i++)
    {
        temp=jagged[1][i];
        jagged[1][i] = jagged [4][i];
        jagged[4][i] = temp;
    }

    for (int k = 0; k < 25; k++) 
    {
        int i = k / 5;
        int j = k % 5;
        if (k%5==0)
        {
            printf("[%d] ", i); 
        }
        if (jagged[i][j] == -1) 
        {
            printf(" ");
        } 
        else 
        {
            printf("%d ", jagged[i][j]);
        }
        if (j == 4) 
        {
            printf("\n");
        }
        
    }
    
    return 0;
}