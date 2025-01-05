#include <stdio.h>

int main()
{
    int max, k;
    scanf("%d %d", &max, &k);

    int queue[k];
    for (int i = 0; i < k; i++)
    {
        queue[i] = 0;
    }

    int front = 0, rear = 0;
    queue[rear] = 1;
    rear = (rear + 1) % k;

    while (1)
    {
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += queue[i];
        }
        if (sum <= max)
        {
            queue[rear] = sum;
            rear = (rear + 1) % k;
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < k; i++)
    {
        printf("%d ", queue[(rear + i) % k]);
    }

    return 0;
}
