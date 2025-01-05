#include <stdio.h>
#include <stdlib.h>

// 定义稀疏矩阵的节点
typedef struct Node
{
    int row;
    int col;
    int value;
    struct Node *right;
    struct Node *down;
} Node;

// 创建新节点
Node *create_node(int row, int col, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->row = row;
    new_node->col = col;
    new_node->value = value;
    new_node->right = NULL;
    new_node->down = NULL;
    return new_node;
}

// 插入节点到稀疏矩阵
// 在行和列的链表中插入一个新节点
void insert_node(Node **row_head, Node **col_head, int row, int col, int value)
{
    // 创建一个新节点
    Node *new_node = create_node(row, col, value);

    // 将新节点插入行链表中
    if (row_head[row] == NULL)
    {
        row_head[row] = new_node;
    }
    else
    {
        Node *temp = row_head[row];
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->right = new_node;
    }

    // 将新节点插入列链表中
    if (col_head[col] == NULL)
    {
        col_head[col] = new_node;
    }
    else
    {
        Node *temp = col_head[col];
        while (temp->down != NULL)
        {
            temp = temp->down;
        }
        temp->down = new_node;
    }
}

// 稀疏矩阵相加
// 遍历矩阵1的每一行，将矩阵2中对应行的元素相加，并输出到标准输出
// 本操作类似于上一道题目，只是需要使用两个稀疏矩阵的行指针数组和列指针数组进行遍历
void sparse_matrix_addition(Node **row_head1, Node **col_head1, Node **row_head2, Node **col_head2, int m)
{
    for (int i = 0; i < m; i++)
    {
        Node *temp1 = row_head1[i];
        Node *temp2 = row_head2[i];
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->col < temp2->col)
            {
                printf("%d %d %d\n", temp1->row, temp1->col, temp1->value);
                temp1 = temp1->right;
            }
            else if (temp1->col > temp2->col)
            {
                printf("%d %d %d\n", temp2->row, temp2->col, temp2->value);
                temp2 = temp2->right;
            }
            else
            {
                int sum = temp1->value + temp2->value;
                if (sum != 0)
                {
                    printf("%d %d %d\n", temp1->row, temp1->col, sum);
                }
                temp1 = temp1->right;
                temp2 = temp2->right;
            }
        }
        while (temp1 != NULL)
        {
            printf("%d %d %d\n", temp1->row, temp1->col, temp1->value);
            temp1 = temp1->right;
        }
        while (temp2 != NULL)
        {
            printf("%d %d %d\n", temp2->row, temp2->col, temp2->value);
            temp2 = temp2->right;
        }
    }
}

// 主函数
int main()
{
    int m, n, t1, t2;
    // 从标准输入读取四个整数，若读取失败则返回1
    if (scanf("%d %d %d %d", &m, &n, &t1, &t2) != 4)
    {
        return 1;
    }

    // 分配内存空间用于存储稀疏矩阵的行指针数组和列指针数组
    Node **row_head1 = (Node **)malloc(m * sizeof(Node *));
    Node **col_head1 = (Node **)malloc(n * sizeof(Node *));
    Node **row_head2 = (Node **)malloc(m * sizeof(Node *));
    Node **col_head2 = (Node **)malloc(n * sizeof(Node *));

    // 初始化行指针数组
    for (int i = 0; i < m; i++)
    {
        row_head1[i] = NULL;
        row_head2[i] = NULL;
    }

    // 初始化列指针数组
    for (int j = 0; j < n; j++)
    {
        col_head1[j] = NULL;
        col_head2[j] = NULL;
    }

    // 读取 t1 组稀疏矩阵元素信息并插入矩阵1
    for (int i = 0; i < t1; i++)
    {
        int row, col, value;
        // 从标准输入读取三个整数，若读取失败则返回1
        if (scanf("%d %d %d", &row, &col, &value) != 3)
        {
            return 1;
        }
        // 将读取的稀疏矩阵元素插入到矩阵1
        insert_node(row_head1, col_head1, row, col, value);
    }

    // 读取 t2 组稀疏矩阵元素信息并插入矩阵2
    for (int i = 0; i < t2; i++)
    {
        int row, col, value;
        // 从标准输入读取三个整数，若读取失败则返回1
        if (scanf("%d %d %d", &row, &col, &value) != 3)
        {
            return 1;
        }
        // 将读取的稀疏矩阵元素插入到矩阵2
        insert_node(row_head2, col_head2, row, col, value);
    }

    // 稀疏矩阵相加
    sparse_matrix_addition(row_head1, col_head1, row_head2, col_head2, m);

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
    for (int i = 0; i < m; i++)
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

    // 释放矩阵内存指针数组的内存空间
    free(row_head1);
    free(col_head1);
    free(row_head2);
    free(col_head2);

    return 0;
}