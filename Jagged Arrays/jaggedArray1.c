#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n;
    printf("Enter number of characters: ");
    scanf("%d", &n);
    getchar(); //

    char *c = (char*)malloc(sizeof(char)*(n+1)); //n + 1 to accommodate null-terminator

    printf("Enter %d characters: " , n);
    for (int i = 0; i<n; i++)
        scanf("%c", c+i);
    c[n] = '\0';
    printf("%s\n",c);

    free(c);
    c = NULL;    
}
