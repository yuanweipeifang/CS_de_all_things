#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void mergeArrays(int arr1[], int m, int arr2[], int n, int arr3[]);

int main()
{
    int a, b;
    scanf("%d", &a);
    int *arr1 = (int *)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &b);
    int *arr2 = (int *)malloc(b * sizeof(int));
    for (int j = 0; j < b; j++)
    {
        scanf("%d", &arr2[j]);
    }

    int *arr3 = (int *)malloc((a + b) * sizeof(int));
    mergeArrays(arr1, a, arr2, b, arr3);

    for (int cnt = 0; cnt < a + b; cnt++)
    {
        printf("%d\n", arr3[cnt]);
    }

    free(arr1);
    free(arr2);
    free(arr3);
    system("pause");
    return 0;
}

void mergeArrays(int arr1[], int m, int arr2[], int n, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        arr3[k++] = (arr1[i] < arr2[j]) ? arr1[i++] : arr2[j++];
    }
    while (i < m)
    {
        arr3[k++] = arr1[i++];
    }
    while (j < n)
    {
        arr3[k++] = arr2[j++];
    }
}
