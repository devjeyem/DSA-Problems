#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int p,v,t;
    int ctr = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &p, &v, &t);
        if (p ==1 || v == 1 || t == 1)
        {
            if (p == 1 && v == 1)
            {
                ctr++;
                continue;
            }
            else if (v == 1 && t == 1)
            {
                ctr++;
                continue;
            }
            else if  (p == 1 && t == 1)
            {
                ctr++;
                continue;
            }
        }
    }
    printf("%d", ctr);
    
}