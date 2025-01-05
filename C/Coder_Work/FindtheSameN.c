#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int hash[1000], c[1000] = {0};
    for (int i = 0; i < 2 * n; i++)
    {
        scanf("%d", &hash[i]);
    }
    for (int i = 0; i < 2 * n; i++)
    {
        c[hash[i]]++;
        if (c[hash[i]] == n)
        {
            printf("%d\n", hash[i]);
        }
    }
    return 0;
}