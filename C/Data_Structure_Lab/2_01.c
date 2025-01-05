#include <stdio.h>
#include <stdlib.h>

// 宏定义错误常量和最大值常量
#define ERROR 1
#define MAX 10000

// 定义三元组结构体
typedef struct Triple
{
    int i, j, x;
} Triple;

// 定义RLSmatrix结构体
typedef struct
{
    Triple data[MAX];
    int an, bn, cn;
    Triple *next;
    Triple *pre;
} RLSmatrix;

// 交换两个三元组的值
void swap(Triple *a, Triple *b)
{
    Triple temp = *a;
    *a = *b;
    *b = temp;
    return;
}

/*
 * 转置三元组矩阵
 * 定义一个函数transition，接受一个RLSmatrix类型的指针matrix作为参数
 * 该函数将matrix中每个元素的i和j成员进行交换，并使用冒泡排序对matrix中的data数组进行排序
 */
void transition(RLSmatrix *matrix)
{
    int i, j, x;
    int swapped;
    for (i = 0; i < matrix->cn; i++)
    {
        // 对matrix中每个元素的i和j成员进行交换
        int a = matrix->data[i].i;
        matrix->data[i].i = matrix->data[i].j;
        matrix->data[i].j = a;
    }
    // 使用冒泡排序对matrix中的data数组进行排序
    for (j = 0; j < matrix->cn - 1; j++)
    {
        swapped = 0;
        for (x = 0; x < matrix->cn - 1 - j; x++)
        {
            // 如果相邻两个元素的x成员不是按升序排列，则交换它们
            if (matrix->data[x].x > matrix->data[x + 1].x)
            {
                // 调用swap函数交换matrix->data[x]和matrix->data[x+1]
                swap(&matrix->data[x], &matrix->data[x + 1]);
                swapped = 1;
            }
        }
        // 如果本轮循环没有发生元素交换，则已经排好序，跳出循环
        if (!swapped)
        {
            break;
        }
    }
    return;
}

// 打印三元组矩阵
void print_triple(RLSmatrix *matrix)
{
    // 打印三元组数组的元素
    // matrix: 指向存储三元组的RLSmatrix的指针
    int i;
    for (i = 0; i <= matrix->cn - 1; i++)
    {
        // 逐行打印三元组的成员变量 i, j, x
        printf("%d %d %d\n", matrix->data[i].i, matrix->data[i].j, matrix->data[i].x);
    }
    return;
}

int main()
{
    int m, n;
    int i;
    scanf("%d %d", &m, &n);

    // 定义RLSmatrix类型的变量
    RLSmatrix matrix;
    matrix.an = m;
    matrix.bn = n;
    matrix.cn = 0;

    for (i = 0; i < n; i++)
    {
        int a, b, c;

        // 输入三元组的值
        scanf("%d", &a);
        getchar();
        scanf("%d", &b);
        getchar();
        scanf("%d", &c);
        if (a == 0 && b == 0 && c == 0)
        {
            break;
        }

        // 保存输入的三元组值到RLSmatrix中
        matrix.data[i].i = a;
        matrix.data[i].j = b;
        matrix.data[i].x = c;
        matrix.cn++;
    }

    // 转置三元组矩阵并打印
    transition(&matrix);
    print_triple(&matrix);
    return 0;
}
