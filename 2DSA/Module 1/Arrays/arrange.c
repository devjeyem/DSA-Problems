#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int ctr[201];   //store the frequency for -100 to 100
    memset(ctr,0,sizeof(ctr)); //initialize to zero 
    int maxCtr = 0; //track max

    for (int i = 0; i<20 ; i++)
    {
        int x;
        scanf("%d",&x);
        ctr[x+100]++; 
        if (ctr[x+100] > maxCtr)
            maxCtr = ctr[x+100];
    }

    for (int i = 0; i<201; i++)
    {
        if (ctr[i] == maxCtr)
            printf("%d ", i-100);
    }
}