#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int main()
{
    int a, b;
    int i, j;

    scanf("%d", &a);
    int *arr1 = (int *)malloc(a * sizeof(int));
    for (i = 0; i < a; i++)
    {
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &b);
    int *arr2 = (int *)malloc(b * sizeof(int));
    for (j = 0; j < b; j++)
    {
        scanf("%d", &arr2[j]);
    }

    int *arr3 = (int *)malloc((a + b) * sizeof(int));
    i = 0, j = 0;
    int k = 0;
    while (i < a && j < b)
    {
        arr3[k++] = (arr1[i] < arr2[j]) ? arr1[i++] : arr2[j++];
    }

    while (i < a)
    {
        arr3[k++] = arr1[i++];
    }
    while (j < b)
    {
        arr3[k++] = arr2[j++];
    }

    for (int cnt = 0; cnt < k; cnt++)
    {
        printf("%d\n", arr3[cnt]);
    }

    if (a + b >= ARRAY_SIZE(arr3))
    {
        while (i < a)
        {
            arr3[k++] = arr1[i++];
        }
        while (j < b)
        {
            arr3[k++] = arr2[j++];
        }
    }
    
    free(arr1);
    free(arr2);
    free(arr3);
    system("pause");
    return 0;
}
