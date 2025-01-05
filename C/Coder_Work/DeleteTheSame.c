#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node, Node;

// 此处使用尾差法进行链表的建立
Node *insert(Node *head, int x)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
    }
    else
    // 此处用指针进行遍历，当指针运行到末尾时添加即可
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
    return head;
}

Node *delele(Node *head)
{
    Node *p = head->next;
    Node *q = head;
    while (p != NULL)
    {
        if (p->data == q->data)
        {
            q->next = p->next;
            free(p);
            p = q->next;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
    return head;
}
int main()
{
    int m, x;
    scanf("%d", &m);
    Node *head = NULL;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);
        head = insert(head, x);
    }
    head = delele(head);
    for (Node *p = head; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }
    system("pause");
    return 0;
}