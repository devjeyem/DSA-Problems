#include <stdio.h>
#include <stdlib.h>

int main() 
{
    void *x = (void*)malloc(4*sizeof(void));

    *((int*)x) = 3;
    printf("%d\n", *((int*)x));

    *((int**)(x+1)) = malloc(2*sizeof(void*));
    *(*((int**)x+1)) = 1;
    //*(*((int**)x+2)) = 2;
    printf("%d",  **((int**)x+1));
    //printf("%d",  **((int**)x+2));


    return 0;
}