#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    char s[1000];
    int ctr = 0;

    for  (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        if (strcmp(s, "++X") == 0 || strcmp(s, "X++") == 0)
        {
            ctr++;
        }
        else if (strcmp(s, "--X") == 0 || strcmp(s, "X--") == 0)
        {
            ctr--;
        }
    }
    printf("%d\n", ctr);
}