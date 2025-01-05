#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    float ratio;       // 系数
    int index;         // 指数
    struct Node *next; // 下一个指针域
} *PNode, *LinkList;

LinkList Create_Link()
{
    LinkList head;
    PNode p, q;
    float ratio; // 系数
    int index;   // 指数

    // 创建空链表
    head = (struct Node *)malloc(sizeof(struct Node));
    head->next = NULL;

    q = head;
    scanf("%f %d", &ratio, &index);
    while (ratio != 0 || index != 0) // 结束条件是系数和指数同时为0
    {
        p = (struct Node *)malloc(sizeof(struct Node)); // 给新结点分配空间
        p->next = NULL;
        // 采用尾插法的方式插入新的结点
        q->next = p;
        q = p;
        p->index = index;
        p->ratio = ratio;
        scanf("%f %d", &ratio, &index);
    }
    return head;
}

void Sort_Link(LinkList head)
{
    PNode p, q;
    // 定义中间变量进行数据的交换
    float temp1;
    int temp2;
    // 进行冒泡排序
    for (p = head->next; p != NULL; p = p->next)
        for (q = p->next; q != NULL; q = q->next)
        {
            if (q->index < p->index)
            {
                temp1 = q->ratio;
                q->ratio = p->ratio;
                p->ratio = temp1;
                temp2 = q->index;
                q->index = p->index;
                p->index = temp2;
            }
        }
}

void Add_List(LinkList llist1, LinkList llist2)
{
    PNode p, q, pre, temp;
    p = llist1->next;
    q = llist2->next;
    pre = llist1; // 始终用pre表示p的前一个结点
    while (p && q)
    {
        if (q->index < p->index) // 进行前插
        {
            temp = q->next; // 防止llist2的丢失
            q->next = p;
            pre->next = q;
            pre = q;
            q = temp;
        }
        else if (q->index > p->index) // 继续遍历
        {
            pre = p;
            p = p->next;
        }
        else
        {
            if (q->ratio + p->ratio == 0) // 相加系数为0，进行删除
            {
                pre->next = p->next;
                free(p);
            }
            else
            {
                p->ratio = p->ratio + q->ratio;
                pre = p;
            }
            p = pre->next;
            temp = q;
            q = q->next;
            free(temp);
        }
    }
    if (q) // 如果q中仍有结点，直接插入到llist1的末尾即可
    {
        pre->next = q;
    }
    free(llist2);
}

void print(LinkList head)
{
    PNode p;
    for (p = head->next; p != NULL; p = p->next)
    {
        printf("%.0f %d ", p->ratio, p->index);
    }
}

int main()
{
    LinkList llist1 = Create_Link();
    LinkList llist2 = Create_Link();
    Sort_Link(llist1);
    Sort_Link(llist2);
    Add_List(llist1, llist2);
    print(llist1);
    system("pause");
    return 0;
}