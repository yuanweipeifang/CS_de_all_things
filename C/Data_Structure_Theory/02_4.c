#include <stdio.h>
#include <stdlib.h>

#define ERROR 0

// 定义链表节点结构
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 合并两个有序链表为一个递减有序链表
Node *mergeLists(Node *headA, Node *headB)
{
    // 创建新链表头节点
    Node *headC = (Node *)malloc(sizeof(Node));
    headC->next = NULL;
    Node *tailC = headC;

    // 合并两个链表
    while (headA && headB)
    {
        if (headA->data <= headB->data)
        {
            tailC->next = headA;
            headA = headA->next;
        }
        else
        {
            tailC->next = headB;
            headB = headB->next;
        }
        tailC = tailC->next;
    }

    // 将剩余节点接到新链表尾部
    tailC->next = headA ? headA : headB;

    // 释放头节点并返回合并后的链表头
    Node *temp = headC;
    headC = headC->next;
    free(temp);

    return headC;
}

// 逆序输出链表
void reversePrint(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    reversePrint(head->next);
    printf("%d ", head->data);
}

int main()
{
    int m, n;
    // 输入检测
    if (scanf("%d %d", &m, &n) != 2 || m <= 0 || n <= 0 || m > 100 || n > 100)
    {
        return ERROR;
    }

    // 构建链表 A
    Node *headA = (Node *)malloc(sizeof(Node));
    Node *tempA = headA;
    for (int i = 0; i < m; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (scanf("%d", &newNode->data) != 1)
        {
            return ERROR;
        }
        newNode->next = NULL;
        tempA->next = newNode;
        tempA = tempA->next;
    }

    // 构建链表 B
    Node *headB = (Node *)malloc(sizeof(Node));
    Node *tempB = headB;
    for (int i = 0; i < n; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (scanf("%d", &newNode->data) != 1)
        {
            return ERROR;
            ;
        }
        newNode->next = NULL;
        tempB->next = newNode;
        tempB = tempB->next;
    }

    // 合并链表并逆序输出
    Node *headC = mergeLists(headA->next, headB->next);
    reversePrint(headC);

    return 0;
}
