#include <stdio.h>
#include <stdlib.h>

#define ERROR 0

// 定义单链表结点结构
typedef struct Node
{
    int data;          // 结点数据
    struct Node *next; // 指向下一个结点的指针
} Node;

// 以一维数组作为存储结构的线性表就地逆置算法
void reverseArray(int *arr, int length)
{
    int i, temp;
    for (i = 0; i < length / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[length - 1 - i];
        arr[length - 1 - i] = temp;
    }
}

// 以单链表作为存储结构的线性表就地逆置算法
void reverseLinkedList(Node **head)
{
    Node *prev = NULL;     // 当前结点的前一个结点
    Node *current = *head; // 当前结点
    Node *next = NULL;     // 当前结点的下一个结点

    while (current != NULL)
    {
        next = current->next; // 保存当前结点的下一个结点
        current->next = prev; // 将当前结点的指针指向前一个结点，实现逆置
        prev = current;       // 更新前一个结点为当前结点
        current = next;       // 更新当前结点为下一个结点
    }

    *head = prev; // 更新头结点为逆置后的链表的第一个结点
}

// 创建单链表
Node *createLinkedList(int *arr, int length)
{
    Node *head = NULL;
    Node *current = NULL;
    for (int i = length - 1; i >= 0; i--)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = arr[i]; // 设置新结点的数据
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;    // 如果是第一个结点，将头结点指向新结点
            current = newNode; // 同时将当前结点指向新结点
        }
        else
        {
            current->next = newNode; // 如果不是第一个结点，将当前结点的next指针指向新结点
            current = newNode;       // 更新当前结点为新结点
        }
    }
    return head;
}

// 打印单链表
void printLinkedList(Node *head)
{
    Node *current = head; // 从头结点开始遍历链表

    while (current != NULL)
    {
        printf("%d ", current->data); // 打印当前结点的数据
        current = current->next;      // 更新当前结点为下一个结点
    }
    printf("\b");
    printf("\n");
}

int main()
{
    int elenum;
    if (scanf("%d", &elenum) != 1 || elenum <= 0 || elenum >= 1000)
    {
        return ERROR;
    }

    int *arr = (int *)malloc(sizeof(int) * elenum);
    for (int i = 0; i < elenum; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            free(arr);
            return ERROR;
        }
    }

    // 使用一维数组作为存储结构的线性表就地逆置
    reverseArray(arr, elenum);
    for (int i = 0; i < elenum; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\b");
    printf("\n");

    // 使用单链表作为存储结构的线性表就地逆置
    Node *head = createLinkedList(arr, elenum);
    reverseLinkedList(&head);
    printLinkedList(head);

    free(arr);
    free(head);

    return 0;
}
