#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int num = 10;
    int *p , **q,**r,***s,***t,***u,***v;
    p=&num;
    q=&p;
    r=&p;
    s=&q;
    t=&q;
    u=&r;
    v=&r;

    printf("%d ", *p);
    printf("%d ", **q);
    printf("%d ", **r);    
    printf("%d ", ***s);
    printf("%d ", ***t);
    printf("%d ", ***u);
    printf("%d ", ***v);

    printf("%p ", p);
    printf("%p ", q);
    printf("%p ", r);    
    printf("%p ", s); 
    printf("%p ", t);
    printf("%p ", u);
    printf("%p ", v); 

    printf("\n");

     int a = 1, b = 2, c = 3, d = 4, e = 5;
    int *arr[] = {&a, &b, &c, &d, &e}; // Array of pointers to integers
    for (int i = 0; i < 5; i++) 
    {
        printf("%d ", *arr[i]); // Print the address stored in each pointer
    }
  

    int *arr2 = (int*)malloc(5*sizeof(int));
    for (int i = 0;i<5;i++)
    {
        arr2[i] = i + 1;
        printf("%d ", arr2[i]);
    }

    free(arr2); 
    arr2 = NULL;
       
}
