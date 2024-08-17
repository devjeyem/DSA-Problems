#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    double weights[10] ;
    double ave = 0,sum=0;
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        weights[i] = rand() % 11; // Generate random number between 0 and 10   
    }

    for (int i = 0;i<10;i++) 
    {
        printf("%.2lf, ", weights[i]);
        sum += weights[i];
        if (i==9)
        {
            ave = sum/10.0;
            printf("\n%2lf\n", ave);
            printf("Above ave = " );
            for (int j = 0; j<10;j++)
            {
                if (ave<weights[j])
                {
                    printf("%.2lf ", weights[j]);
                }
            }
        }
    }
   
 


}