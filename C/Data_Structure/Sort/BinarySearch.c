#include <stdio.h>
// 此程序的输入序列为升序排列

int binarysearch(int *arr, int n, int x)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1; // 此处更新左边指针，缩小右半边
        }
        else
        {
            right = mid - 1; // 此处更新了右边指针，缩小左半边
        }
    }
    return -1;
}

int main()
{
    int n, x;
    scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);
    int pos = binarysearch(arr, n, x);
    printf("%d", pos);
    return 0;
}