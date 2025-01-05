#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 删除三个链表中的共同元素
Node *deleteCommonElements(Node *A, Node *B, Node *C)
{
    Node *result = NULL; // 结果链表的头指针
    Node *tail = NULL;   // 结果链表的尾指针

    // 遍历三个链表，删除共同元素
    while (A != NULL && B != NULL && C != NULL)
    {
        if (A->data == B->data && A->data == C->data)
        {
            A = A->next;
            B = B->next;
            C = C->next;
        }
        else if (A->data < B->data || A->data < C->data)
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->data = A->data;
            newNode->next = NULL;

            if (result == NULL)
            {
                result = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }

            A = A->next;
        }
        else if (B->data < A->data)
        {
            B = B->next;
        }
        else if (C->data < A->data)
        {
            C = C->next;
        }
    }

    // 将剩余元素添加到结果链表中
    while (A != NULL)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = A->data;
        newNode->next = NULL;

        if (result == NULL)
        {
            result = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        A = A->next;
    }

    return result;
}

// 打印链表元素
void printLinkedList(Node *head)
{
    Node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 创建链表
Node *createLinkedList(int n)
{
    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// 释放链表内存
void freeLinkedList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int m, n, p;
    scanf("%d %d %d", &m, &n, &p);

    // 创建三个链表
    Node *A = createLinkedList(m);
    Node *B = createLinkedList(n);
    Node *C = createLinkedList(p);

    // 删除共同元素并打印结果
    Node *result = deleteCommonElements(A, B, C);
    printLinkedList(result);

    // 释放内存
    freeLinkedList(result);
    freeLinkedList(A);
    freeLinkedList(B);
    freeLinkedList(C);

    return 0;
}
