#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} node, *Node;

Node create(int val)
{
    Node new = (Node)malloc(sizeof(struct Node));
    new->val = val;
    new->next = NULL;
    return new;
}

Node merge(Node l1, Node l2)
{
    Node dummy = create(0);
    Node tail = dummy;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy->next;
}

void print(Node l)
{
    while (l)
    {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
}

int main()
{
    Node l1 = NULL, l2 = NULL;
    //! 记得这里指针置空
    Node temp;
    int m, n, val;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &val);
        if (l1 == NULL)
        {
            l1 = create(val);
            temp = l1;
        }
        else
        {
            temp->next = create(val);
            temp = temp->next;
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        if (l2 == NULL)
        {
            l2 = create(val);
            temp = l2;
        }
        else
        {
            temp->next = create(val);
            temp = temp->next;
        }
    }

    Node merged = merge(l1, l2);
    print(merged);

    return 0;
}
