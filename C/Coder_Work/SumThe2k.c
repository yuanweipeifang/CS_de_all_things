#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int SumThe2k(Node *head)
{
    Node *p = head->next;
    int sum = 0;
    while (p != NULL)
    {
        if (p->data % 2 == 0)
        {
            sum += p->data;
        }
        p = p->next;
    }
    return sum;
}

Node *create(int n)
{
    Node *h, *p, *s;
    int i = 0;
    h = p = (Node *)malloc(sizeof(Node));

    for (int i = 1; i < n; i++)
    {
        s = (Node *)malloc(sizeof(Node));
        s->data = rand() % 16;
        s->next = p->next;
        p->next = s;
        p = p->next;
    }

    p->next = NULL;
    return h;
}

int main()
{
    Node *head;
    int a;
    scanf("%d", &a);
    head = create(a);
    printf("Head");
    while (head)
    {
        head->data = rand() % 20;
        head->next = NULL;

        printf("->%d", head->data);
        head = head->next;
    }
    printf("\n");
    int sum = SumThe2k(head);

    printf("\nSUM=%d\n", sum);

    return 0;
}
