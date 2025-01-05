#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct Node
{
    int val;
    struct Node *next;
} Node;

Node *removeNthFromEnd(Node *head, int n)
{
    // 创建一个虚拟头节点，方便处理头节点被删除的情况
    Node *dummy = (Node *)malloc(sizeof(Node));
    dummy->next = head;
    Node *fast = dummy;
    Node *slow = dummy;

    // 先让fast指针向前移动n步
    for (int i = 0; i < n + 1; i++)
    {
        fast = fast->next;
    }

    // fast和slow同时向前移动，直到fast到达链表末尾
    while (fast != NULL)
    {
        fast = fast->next;        slow = slow->next;
    }

    // 删除slow指向的节点的下一个节点，即倒数第n个节点
    slow->next = slow->next->next;

    // 返回虚拟头节点的下一个节点作为新的头节点
    return dummy->next;
}

// 创建链表
Node *createList(int arr[], int size)
{
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 0; i < size; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->val = arr[i];
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            tail->next = newNode;
        }
        tail = newNode;
    }
    return head;
}

// 打印链表
void printList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 2;
    Node *head = createList(arr, sizeof(arr) / sizeof(arr[0]));
    printf("Original list: ");
    printList(head);
    head = removeNthFromEnd(head, n);
    printf("List after removing the %dth node from the end: ", n);
    printList(head);
    system("pause");
    return 0;
}