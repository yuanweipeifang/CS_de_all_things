#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct
{
    int rear;
    int length;
    int arr[MAX];
} Queue;

Queue q;

int main()
{
    int len = 0;
    scanf("%d", &len);

    for (int i = 0; i < len; i++)
    {
        scanf("%d", &q.arr[q.rear++]);
        char c = getchar();
        if (c == '\n')
            break;
    }

    if (q.rear >= len)
    {
        printf("yes\n");
        q.rear = len;
    }
    else
    {
        printf("no\n");
    }

    int val, front = 0;
    scanf("%d", &val);
    while (front < q.rear && q.arr[front] != val)
        ++front;
    ++front;

    for (int i = front; i < q.rear - 1; ++i)
    {
        printf("%d ", q.arr[i]);
    }
    printf("%d\n", q.arr[q.rear - 1]);
    printf("%d\n", q.arr[front]);

    return 0;
}
