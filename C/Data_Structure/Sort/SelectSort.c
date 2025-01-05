#include <stdio.h>
#include <stdlib.h>

void select(int arr[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        // 第二个循环用来寻找交换的位置
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j; // 更新下一次要交换的位置
            }
        }
        // 进行选择排序，将内层循环中找到的指定元素放到未排序序列中的最小位置
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
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
    select(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr); // 释放动态分配的内存
    return 0;
}
