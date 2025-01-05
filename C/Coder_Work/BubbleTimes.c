#include <stdio.h>
int main()
{
    int n, a[1024];
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    // bubble sort
    // 使用冒泡排序算法对数组进行排序
    // i表示当前未排序的元素的位置
    // j表示当前已排序的元素的位置
    // 如果a[i]大于a[j]，则交换两者的位置
    // 重复上述操作，直到数组全部排序完毕
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
            {
                sum++;
                break;
            }
    printf("%d", sum);
    return 0;
} 