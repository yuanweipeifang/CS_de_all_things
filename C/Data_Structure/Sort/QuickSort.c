#include <stdio.h>
#include <stdlib.h>

void quick(int *a, int low, int high)
{
    if (low < high)
    {
        int i = low;
        int j = high;
        int k = a[low];
        while (i < j)
        {
            while (i < j && a[j] > k)
            {
                j--;
            }
            if (i < j)
            {
                a[i++] = a[j];
            }

            while (i < j && a[i] < k)
            {
                i++;
            }
            if (i < j)
            {
                a[j--] = a[i];
            }
        }
        a[i] = k;
        quick(a, low, i - 1);
        quick(a, i + 1, high);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quick(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr); // 释放动态分配的内存
    return 0;
}
