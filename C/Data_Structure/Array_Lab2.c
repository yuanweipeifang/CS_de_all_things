#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void mergeArrays(int arr1[], int m, int arr2[], int n, int arr3[]);
int *inputArray(int size);

int main()
{
    int a, b;
    if (scanf("%d", &a) != 1)
    {
        return 1;
    }

    int *arr1 = inputArray(a);
    if (arr1 == NULL)
    {
        return 1;
    }
    if (scanf("%d", &b) != 1)
    {
        free(arr1);
        return 1;
    }

    int *arr2 = inputArray(b);
    if (arr2 == NULL)
    {
        free(arr1);
        return 1;
    }

    int *arr3 = (int *)malloc((a + b) * sizeof(int));
    if (arr3 == NULL)
    {
        free(arr1);
        free(arr2);
        return 1;
    }
    
    mergeArrays(arr1, a, arr2, b, arr3);

    for (int cnt = 0; cnt < a + b; cnt++)
    {
        printf("%d\n", arr3[cnt]);
    }

    free(arr1);
    free(arr2);
    free(arr3);
    return 0;
}

void mergeArrays(int arr1[], int m, int arr2[], int n, int arr3[])
{
    int i = 0, j = 0, k = 0;
    for (k = 0; k < m + n; k++)
    {
        if (i < m && j < n)
        {
            arr3[k] = (arr1[i] < arr2[j]) ? arr1[i++] : arr2[j++];
        }
        else if (i < m)
        {
            arr3[k] = arr1[i++];
        }
        else
        {
            arr3[k] = arr2[j++];
        }
    }
}

int *inputArray(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < size; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            free(arr);
            return NULL;
        }
    }
    return arr;
}