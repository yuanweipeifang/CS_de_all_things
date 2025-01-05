#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 定义双链表结点结构
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} node, *DNode;

//建立空链表
void CreateList(DNode *p)
{
    (*p) = (DNode)malloc(sizeof(node));
    (*p)->prev = *p;
    (*p)->next = *p;
}

//建立链表
DNode Createlist(DNode head)
{
    int i;
    DNode p;
    p = head;
    for (i = 0; i <= 520; i++)//创建链表的大小要满足题目的要求
    {
        DNode q = (DNode)malloc(sizeof(node));
        q->data = 0;//提前将数据域指置零
        q->prev = p;
        p->next = q;
        q->next = head; //形成双向链表
        head->prev = q;
        p = p->next;
    }
    return head;
}

//封装一个新的函数用于释放动态分配的内存
void free_func(DNode head)
{
    DNode current = head->next;
    //保证内存充分释放
    while (current != head)
    {
        DNode temp = current;
        current = current->next;
        free(temp);
    }
    //最后释放头结点
    free(head);
}

int main()
{
    int n, i;
    int tmp1, tmp2, tmp3, tmp4;
    if (scanf("%d", &n) != 1)
    {
        return 1;
    }//检验输入是否合法

    DNode Rn_list = NULL, sum_list = NULL;
    DNode p, q;
    CreateList(&Rn_list);
    CreateList(&sum_list);
    Rn_list = Createlist(Rn_list);
    sum_list = Createlist(sum_list);

    Rn_list->next->data = 2;    //第一位储存2，即2*R(1)=2
    sum_list->next->data = 2;  

    for (i = 1; i <= 5000; i++)
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

    DNode result;
    result = sum_list->next->next;

    // 输出结果
    for (i = 0; i < n; i++)
    {
        printf("%d", result->data);
        result = result->next;
    }

    // 释放内存
    free_func(Rn_list);
    free_func(sum_list);

    return 0;
}
