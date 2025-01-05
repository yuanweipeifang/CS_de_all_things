#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

// 定义稀疏矩阵的结点结构
typedef struct Node
{
    int row;            // 行号
    int col;            // 列号
    int value;          // 值
    struct Node *right; // 指向右边相邻结点
    struct Node *down;  // 指向下方相邻结点
} Node;

// 创建新结点
Node *create_node(int row, int col, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node)); // 为新结点分配内存空间
    new_node->row = row;
    new_node->col = col;
    new_node->value = value;
    new_node->right = NULL;
    new_node->down = NULL;
    return new_node;
}

// 在稀疏矩阵中插入新结点
void insert_node(Node **row_head, Node **col_head, int row, int col, int value)
{
    Node *new_node = create_node(row, col, value);
    if (row_head[row] == NULL)
    {                             // 若该行尚无结点
        row_head[row] = new_node; // 直接将新结点插入作为该行的头结点
    }
    else
    {
        Node *temp = row_head[row]; // 遍历找到该行的尾结点
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->right = new_node; // 插入新结点到该行的尾端
    }

    if (col_head[col] == NULL)
    {                             // 若该列尚无结点
        col_head[col] = new_node; // 直接将新结点插入作为该列的头结点
    }
    else
    {
        Node *temp = col_head[col]; // 遍历找到该列的尾结点
        while (temp->down != NULL)
        {
            temp = temp->down;
        }
        temp->down = new_node; // 插入新结点到该列的尾端
    }
}

// 稀疏矩阵相乘
void sparse_matrix_multiplication(Node **row_head1, Node **col_head2, int m, int n, int p)
{
    for (int i = 0; i < m; i++)
    { // 遍历row_head1的每一行
        for (int j = 0; j < p; j++)
        {                               // 遍历col_head2的每一列
            int sum = 0;                // 初始化乘积的和为0
            Node *temp1 = row_head1[i]; // 取出row_head1的第i行
            Node *temp2 = col_head2[j]; // 取出col_head2的第j列
            while (temp1 != NULL && temp2 != NULL)
            { // 循环直到遍历完temp1或temp2
                if (temp1->col < temp2->row)
                { // 如果temp1当前列小于temp2当前行，移动temp1向右
                    temp1 = temp1->right;
                }
                else if (temp1->col > temp2->row)
                { // 如果temp1当前列大于temp2当前行，移动temp2向下
                    temp2 = temp2->down;
                }
                else
                {                                       // 如果temp1当前列等于temp2当前行
                    sum += temp1->value * temp2->value; // 将对应位置的值相乘并加到sum中
                    temp1 = temp1->right;               // 移动temp1向右
                    temp2 = temp2->down;                // 移动temp2向下
                }
            }
            if (sum != 0)
            {                                            // 若结果不为零，则输出
                printf("%d %d %d\n", i + 1, j + 1, sum); // 输出乘积的行、列、值
            }
        }
    }
}

int main()
{
    int m, n, t1, p;
    if (scanf("%d %d", &m, &n) != 2)
    {
        return ERROR;
    }

    Node **row_head1 = (Node **)malloc(m * sizeof(Node *)); // 初始化矩阵1的行头指针数组
    Node **col_head1 = (Node **)malloc(n * sizeof(Node *)); // 初始化矩阵1的列头指针数组

    // 初始化矩阵1的行列头指针数组
    for (int i = 0; i < m; i++)
    {
        row_head1[i] = NULL;
    }

    for (int j = 0; j < n; j++)
    {
        col_head1[j] = NULL;
    }

    // 矩阵1输入
    while (1)
    {
        int row, col, value;
        if (scanf("%d %d %d", &row, &col, &value) != 3)
        {
            return ERROR;
        }
        if (row == 0 && col == 0 && value == 0)
        {
            break;
        }
        insert_node(row_head1, col_head1, row - 1, col - 1, value);
    }

    if (scanf("%d %d", &t1, &p) != 2)
    {
        return ERROR;
    }

    Node **row_head2 = (Node **)malloc(t1 * sizeof(Node *)); // 初始化矩阵2的行头指针数组
    Node **col_head2 = (Node **)malloc(p * sizeof(Node *));  // 初始化矩阵2的列头指针数组

    // 初始化矩阵2的行列头指针数组
    for (int i = 0; i < t1; i++)
    {
        row_head2[i] = NULL;
    }

    for (int j = 0; j < p; j++)
    {
        col_head2[j] = NULL;
    }

    // 矩阵2输入
    while (1)
    {
        int row, col, value;
        if (scanf("%d %d %d", &row, &col, &value) != 3)
        {
            return ERROR;
        }

        if (row == 0 && col == 0 && value == 0)
        {
            break;
        }
        insert_node(row_head2, col_head2, row - 1, col - 1, value);
    }

    // 稀疏矩阵相乘
    sparse_matrix_multiplication(row_head1, col_head2, m, n, p);

    // 释放矩阵1的内存空间
    for (int i = 0; i < m; i++)
    {
        Node *temp = row_head1[i];
        Node *prev = NULL;
        while (temp != NULL)
        {
            Node *next = temp->right;
            free(temp);
            temp = next;
        }
    }

    // 释放矩阵2的内存空间
    for (int i = 0; i < t1; i++)
    {
        Node *temp = row_head2[i];
        Node *prev = NULL;
        while (temp != NULL)
        {
            Node *next = temp->right;
            free(temp);
            temp = next;
        }
    }

    // 释放矩阵1和矩阵2的行列头指针数组的内存空间
    free(row_head1);
    free(col_head1);
    free(row_head2);
    free(col_head2);

    return 0;
}