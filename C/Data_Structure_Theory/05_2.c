#include <stdio.h>
#include <stdlib.h>

// 定义稀疏矩阵的节点
typedef struct Node
{
    int row;
    int col;
    int value;
    struct Node *next;
} Node;

// 创建新节点
Node *create_node(int row, int col, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->row = row;
    new_node->col = col;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// 插入节点到稀疏矩阵
void insert_node(Node **head, int row, int col, int value)
{
    Node *new_node = create_node(row, col, value);
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// 释放稀疏矩阵内存
void free_matrix_memory(Node **head)
{
    Node *temp = *head;
    while (temp != NULL)
    {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

// 稀疏矩阵相加
void sparse_matrix_addition(Node *head1, Node *head2)
{
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->row < head2->row || (head1->row == head2->row && head1->col < head2->col))
        {
            printf("%d %d %d\n", head1->row, head1->col, head1->value);
            head1 = head1->next;
        }
        else if (head1->row > head2->row || (head1->row == head2->row && head1->col > head2->col))
        {
            printf("%d %d %d\n", head2->row, head2->col, head2->value);
            head2 = head2->next;
        }
        else
        {
            int sum = head1->value + head2->value;
            if (sum != 0)
            {
                printf("%d %d %d\n", head1->row, head1->col, sum);
            }
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    while (head1 != NULL)
    {
        printf("%d %d %d\n", head1->row, head1->col, head1->value);
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        printf("%d %d %d\n", head2->row, head2->col, head2->value);
        head2 = head2->next;
    }
}

// 主函数
int main()
{
    int m, n, t1, t2;
    if (scanf("%d %d %d %d", &m, &n, &t1, &t2) != 4)
    {
        return 1;
    }

    Node *head1 = NULL;
    Node *head2 = NULL;

    for (int i = 0; i < t1; i++)
    {
        int row, col, value;
        if (scanf("%d %d %d", &row, &col, &value) != 3)
        {
            return 1;
        }
        insert_node(&head1, row, col, value);
    }

    for (int i = 0; i < t2; i++)
    {
        int row, col, value;
        if (scanf("%d %d %d", &row, &col, &value) != 3)
        {
            return 1;
        }
        insert_node(&head2, row, col, value);
    }

    sparse_matrix_addition(head1, head2);

    free_matrix_memory(&head1);
    free_matrix_memory(&head2);

    return 0;
}
