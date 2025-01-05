#include <stdio.h>

int quick_sort(int *a, int low, int high)
{
    if (low < high)
    {                // 当两个下标不重合的时候开始排序
        int i = low; // 把low 和 high 先存起来
        int j = high;
        int k = a[low]; // 把最左边元素和其他数据相比，先存起来
        while (i < j)
        { // 此循环目的是对数据循环排序
            while (i < j && a[j] > k)
            { // 找到右边比k小的数据
                j--;
            }
            if (i < j)
            { // 然后将右边的数据赋值给左边　
                a[i++] = a[j];
            }

            while (i < j && a[i] < k)
            { // 在左边寻找比k大的数据
                i++;
            }
            if (i < j)
            {                  // 然后将左边的数据赋值给刚刚的a[j]
                a[j--] = a[i]; // 因为刚刚是直接赋过去的，a[j]的值没有变
            }
        } // 循环结束时，此子序列已经排序完成
        a[i] = k;                   // 最后将k插入到序列中
        quick_sort(a, low, i - 1);  // 递归调用左半边
        quick_sort(a, i + 1, high); // 递归调用右半边
    }
    return 0;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}