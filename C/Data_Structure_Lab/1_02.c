#include <stdio.h>
#include <stdlib.h>

#define ERROR 0

// 定义双链表结点结构
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node, *DNode;

// 创建空链表
int createList(DNode *p)
{
    (*p) = (DNode)malloc(sizeof(Node));
    if (*p == NULL)
    {
        return ERROR;
    }
    (*p)->prev = *p;
    (*p)->next = *p;
    return 1;
}

// 创建指定大小的链表
DNode createListWithSize(int size)
{
    int i;
    DNode head = NULL;
    if (createList(&head) == ERROR)
    {
        return NULL;
    }
    DNode p = head;
    for (i = 0; i < size; i++)
    {
        DNode q = (DNode)malloc(sizeof(Node));
        if (q == NULL)
        {
            return NULL;
        }
        q->data = 0;
        q->prev = p;
        p->next = q;
        q->next = head;
        head->prev = q;
        p = p->next;
    }
    return head;
}

// 释放链表内存
void freeMemory(DNode head)
{
    DNode current = head->next;
    while (current != head)
    {
        DNode temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}

int main()
{
    int n;
    int tmp1, tmp2, tmp3, tmp4;

    if (scanf("%d", &n) != 1 || n <= 0)
    {
        return ERROR;
    }

    // 创建大小为521的链表
    DNode Rn_list = createListWithSize(521); 
    DNode sum_list = createListWithSize(521);

    //第一位数字写成2
    Rn_list->next->data = 2;
    sum_list->next->data = 2;
    DNode p, q;

    for (int i = 1; i <= 5000; i++)
    {
        p = Rn_list->prev;
        tmp2 = 0;
        while (p != Rn_list)
        {
            tmp1 = p->data * i + tmp2;
            p->data = tmp1 % 10;
            tmp2 = tmp1 / 10;
            p = p->prev;
        }
        tmp3 = 0;
        p = Rn_list->next;
        while (p != Rn_list)
        {
            tmp1 = p->data + tmp3 * 10;
            p->data = tmp1 / (2 * i + 1);
            tmp3 = tmp1 % (2 * i + 1);
            p = p->next;
        }
        tmp4 = 0;
        p = Rn_list->prev;
        q = sum_list->prev;
        while (p != Rn_list)
        {
            tmp1 = p->data + q->data + tmp4;
            q->data = tmp1 % 10;
            tmp4 = tmp1 / 10;
            q = q->prev;
            p = p->prev;
        }
    }

    printf("3.");

    DNode result = sum_list->next->next;

    // 输出结果
    for (int i = 0; i < n; i++)
    {
        printf("%d", result->data);
        result = result->next;
    }

    // 释放内存
    freeMemory(Rn_list);
    freeMemory(sum_list);

    return 0;
}
