#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Step 1: Create an integer pointer p that points to an existing integer
    int x = 10;
    int *p = &x;

    // Step 2: Change the value of the integer pointed by p
    *p = 5;
    printf("%d\n", x); 
    printf("%d\n", *(int*)p);


     // Step 3: Allocate memory for a float and let pi reference it, assign 3.14
    float *pi = (float*)malloc(sizeof(float));
    *pi = 3.14;
    printf("%.2f\n", *pi);

    // Step 4: Redirect p to point to pi and create p_ptr to point to p
    p = (int *)pi; 
    void **p_ptr = (void **)&p;
    printf("Step 4 - Value of pi through p_ptr: %.2f\n", **(float **)p_ptr);


    return 0;
}