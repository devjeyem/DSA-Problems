#include <stdio.h>

void minMax(int arr[], int len,int *min , int *max);

int main()
{
    int a[] = {23,9,2,33,44};
    int min, max;
    int len = sizeof(a)/sizeof(a[0]);
    minMax(a,len,&min,&max);
    printf("%d , %d", min , max); //

    
    

}

void minMax(int arr[], int len,int *min , int *max)
{
    *min = *max = arr[0];
    int i;
    for (int i=1 ; i<len;i++)
    {
        if (arr[i]>*max)
            *max = arr[i];
        if(arr[i]<*min)
            *min = arr[i];
    }
}
