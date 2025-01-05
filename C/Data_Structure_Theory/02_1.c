#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 增加宏定义来为书写程序提供便利
#define MAX_SIZE 1000
#define ERROR 0

// 定义顺序表结构
typedef struct
{
    int data[MAX_SIZE];
    int length;
} SeqList;

// 插入元素X到递增有序的顺序表L中
void insertElement(SeqList *L, int X)
{
    int i, j;
    // 遍历找到插入位置
    for (i = 0; i < L->length; i++)
    {
        if (L->data[i] > X)
        {
            break;
        }
    }
    // 后移元素，腾出位置
    for (j = L->length; j > i; j--)
    {
        L->data[j] = L->data[j - 1];
    }
    // 插入元素X
    L->data[i] = X;
    L->length++;
}

// 打印顺序表
void printList(SeqList L)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    } // 通过遍历整个表来打印
    printf("\n");
}

int main()
{
    SeqList L;
    int elenum, X;

    // 输入顺序表元素个数
    if (scanf("%d", &elenum) != 1 || elenum <= 0 || elenum >= MAX_SIZE)
    {
        return ERROR;
    } // 增加输入检测来保证输入的结果正确

    // 输入顺序表元素
    for (int i = 0; i < elenum; i++)
    {
        if (scanf("%d", &L.data[i]) != 1)
        {
            return ERROR;
        } // 增加输入检测来保证输入的结果正确
    }
    L.length = elenum;

    // 输入要插入的元素X
    if (scanf("%d", &X) != 1)
    {
        return ERROR;
    }

    // 插入元素X到顺序表L中
    insertElement(&L, X);

    // 输出插入后的顺序表
    printList(L);

    return 0;
}
