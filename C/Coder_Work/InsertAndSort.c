#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *create(int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

Node *insertSorted(Node *head, int data)
{
    Node *newnode = create(data);
    if (head == NULL || head->data >= data)
    {
        newnode->next = head;
        return newnode;
    }
    Node *temp = head;
    while (temp->next != NULL && temp->next->data < data)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

void printList(Node *head)
{
    if (head == NULL)
    {
        printf("Head\n");
        return;
    }
    printf("Head");
    Node *temp = head;
    while (temp != NULL)
    {
        printf("->%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;
    int n, data;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head = insertSorted(head, data);
    }

    scanf("%d", &n);
    head = insertSorted(head, n);

    printList(head);

    return 0;
}
