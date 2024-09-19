#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int ****x = (int****)malloc(4*sizeof(int***));
    *(x+0)=  (int***)malloc(sizeof(int**));
    **(x+0) = (int**)malloc(sizeof(int*));
    ***(x+0) = (int*)malloc(sizeof(int));
    ****(x+0) = 3;

    printf("%d ", ****(x+0));

    // Don't forget to free the allocated memory
    free(*(*(*(x+0))));
    free(*(*(x+0)));
    free(*(x+0));
    free(x);

    return 0;
}