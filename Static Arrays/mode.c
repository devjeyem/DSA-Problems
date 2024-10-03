#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findMode(char arr[], int n)
{
    int maxFreq = 0;
    int freq[256];
    memset(freq,0,sizeof(freq));
    for (int i = 0; i<n; i++)
    {
        freq[(int)arr[i]+100]++;
    }

    for (int i = 0; i<256; i++)
    {
        if (freq[i]>maxFreq)
        {
            maxFreq = freq[i];
        }
    }

    if (maxFreq == 1)
        return;
    else{
        for (int i = 0; i<256; i++)
        {
            if (freq[i]==maxFreq)
            {
                printf("%c ", (char)i-100);
            }
        }
    }
}
int main()
{
    char *arr = (char*) malloc(5 * sizeof(char));
    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'a';
    arr[3] = 'b';
    arr[4] = 'c';

    findMode(arr, 5);

}