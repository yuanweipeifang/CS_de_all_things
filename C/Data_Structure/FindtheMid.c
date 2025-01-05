#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

struct Node *creat(int *nums, int cnt)
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *front_p = head;
    struct Node *current_p = NULL;

    for (int i = 0; i < cnt; i++)
    {
        current_p = (struct Node *)malloc(sizeof(struct Node));
        current_p->value = nums[i];

        front_p->next = current_p;
        front_p = current_p;
    }

    front_p->next = NULL;

    return head;
}

void show(struct Node *p)
{
    p = p->next;
    while (p)
    {
        printf("%d ", p->value);
        p = p->next;
    }
}

// line 链表是一个有序链表，现请你找出此链表的中位数，
// 如果链表节点数是偶数，则取中间 2 节点的平均数，保留 2 位小数。
double fun(struct Node *line)
{
    line = line->next;

    // start
    Node *p, *p1 = line, *p2 = line->next;
    int i;
    double sum = 0.0;
    p = line;
    int cnt = 0;
    while (p)
    {
        cnt++;
        p = p->next;
    }

    if (cnt % 2 != 0)
    {
        p = line;
        for (i = 0; i < cnt / 2; i++)
        {
            p = p->next;
        }
        sum = p->value;
    }
    else
    {
        for(i=1;i<(cnt/2);i++){
            p1 = p2;
            p2 = p2->next;
        }
        sum = (p1->value + p2->value) / 2.0;
    }
    return (sum);
    // en
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[100000];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    struct Node *line = creat(a, n);

    printf("%.2lf\n", fun(line));
}