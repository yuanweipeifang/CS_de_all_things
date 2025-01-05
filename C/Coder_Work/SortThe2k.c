#include <stdio.h>
#include <stdlib.h>

void sortArray(int arr[], int n)
{
    int i, j, tmp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] % 2 == 0 && arr[j] % 2 == 0 && arr[i] < arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            if (arr[i] % 2 != 0 && arr[j] % 2 != 0 && arr[i] < arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
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

    sortArray(arr, n);

    for (i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            printf("%d ", arr[i]);
        }
    }

    for (i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            printf("%d ", arr[i]);
        }
    }

    free(arr);
    return 0;
}
