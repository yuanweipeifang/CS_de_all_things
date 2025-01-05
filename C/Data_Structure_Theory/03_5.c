#include <stdio.h>

void reverse(int A[], int start, int end)
{
    while (start < end)
    {
        int temp = A[start];
        A[start] = A[end];
        A[end] = temp;
        start++;
        end--;
    }
}

void rotateArray(int A[], int n, int k)
{
    k = k % n;
    reverse(A, 0, n - 1);
    reverse(A, 0, k - 1);
    reverse(A, k, n - 1);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int A[100]; // 假设数组长度不超过100
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    rotateArray(A, n, k);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}
