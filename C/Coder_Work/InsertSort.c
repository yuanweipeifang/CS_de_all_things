#include <stdio.h>
#include <stdlib.h>

void insert(int arr[], int n)
{
    int i, j, key;          // 定义循环变量i、j和临时变量key
    for (i = 1; i < n; i++) // 遍历数组
    {
        key = arr[i];                  // 将当前元素赋值给key
        j = i - 1;                     // j初始化为当前元素的前一个位置
        while (j >= 0 && arr[j] > key) // 在已排序序列中寻找合适的位置
        {
            arr[j + 1] = arr[j]; // 将大于key的元素后移（此处实际就是把数组向后移动）
            j--;                 // 继续向前搜索
        }
        arr[j + 1] = key; // 插入key到合适的位置
    }
    return; // 函数结束
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    insert(arr, n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}