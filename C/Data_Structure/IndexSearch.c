#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100000

typedef struct node
{
    int value;
    struct node *next;
} Node;

Node *createNode(int *nums, int cnt)
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *front = head;
    Node *curr = NULL;
    for (int i = 0; i < cnt; i++)
    {
        curr = (Node *)malloc(sizeof(Node));
        curr->value = nums[i];
        front->next = curr;
        front = curr;
    }
    return head;
}

void printList(Node *head)
{
    head = head->next;
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int fun(Node *head, int x)
{
    Node *p, *q;
    int index = 1, a = 1;
    p = head->next;
    q = head->next;
    while (p != NULL)
    {
        p = p->next;
        a++;
    }
    while (q != NULL)
    {
        if (q->value != x)
        {
            q = q->next;
            index++;
        }
        else
        {
            break;
        }
    }
    if (index < a)
    {
        return index;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int nums[MAX];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    int value;
    scanf("%d", &value);
    Node *head = createNode(nums, n);
    printf("%d\n", fun(head, value));

    return 0;
}