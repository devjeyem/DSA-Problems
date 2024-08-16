#include <stdio.h>

int main()
{
    int arr[7] = {10,6,3,8,5,1,2};
    int cumulative[7];

    cumulative[0] = arr[0];

    for (int i = 1;i<7;i++)
    {
        cumulative[i] = cumulative[i-1]+arr[i];
    }

    for (int i = 0; i < 7; i++) //
    {
        printf("%d ", cumulative[i]);
    }

}