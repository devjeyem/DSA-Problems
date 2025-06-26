#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int num = 10;
    int *p , **q,**r,***s,***t,***u,***v;
    p=&num;
    q=r=&p;
    s=t=&q;
    u=v=&r;

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
}