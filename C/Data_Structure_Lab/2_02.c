#include <stdio.h>
#include <stdlib.h>

#define ERROR 1

// 定义稀疏矩阵元素结构体
typedef struct
{
    int row;
    int col;
    int value;
} Element;

// 读取稀疏矩阵
void read_sparse_matrix(Element *matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value) != 3)
        {
            exit(1); // 读取失败，退出程序
        }
    }
}

// 打印稀疏矩阵
void print_sparse_matrix(Element C[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d %d %d\n", C[i].row, C[i].col, C[i].value);
    }
}

// 稀疏矩阵相加
void sparse_matrix_addition(Element A[], Element B[], int t1, int t2)
{
    Element C[t1 + t2]; // 创建结果矩阵C，大小为t1 + t2
    int i = 0, j = 0, k = 0; // 初始化变量i，j，k，分别用于遍历A、B和构建C

    // 对A和B进行遍历，将非零元素相加组成C
    while (i < t1 && j < t2)
    {
        // 如果A中的元素位置在B之前，或者在同一行但在列上小于B
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col))
        {
            C[k] = A[i]; // 将A中的元素复制到C
            i++; // 移动到A的下一个元素
        }
        // 如果A和B中的元素位置相同
        else if (A[i].row == B[j].row && A[i].col == B[j].col)
        {
            C[k] = A[i]; // 将A中的元素复制到C
            C[k].value += B[j].value; // 相同位置的元素值相加
            i++; // 移动到A的下一个元素
            j++; // 移动到B的下一个元素
        }
        // 如果B中的元素位置在A之前，或者在同一行但在列上小于A
        else
        {
            C[k] = B[j]; // 将B中的元素复制到C
            j++; // 移动到B的下一个元素
        }
        k++; // 移动到C的下一个位置
    }

    // 处理A中剩余的非零元素
    while (i < t1)
    {
        C[k] = A[i]; // 将A中剩余的元素复制到C
        i++; // 移动到A的下一个元素
        k++; // 移动到C的下一个位置
    }

    // 处理B中剩余的非零元素
    while (j < t2)
    {
        C[k] = B[j]; // 将B中剩余的元素复制到C
        j++; // 移动到B的下一个元素
        k++; // 移动到C的下一个位置
    }

    print_sparse_matrix(C, k); // 打印相加后的稀疏矩阵
}


// 释放矩阵占用的内存
void free_matrix(Element matrix[])
{
    free(matrix);
    return;
}

// 主函数
int main()
{
    int m, n, t1, t2;

    if (scanf("%d %d %d %d", &m, &n, &t1, &t2) != 4)
    {
        return ERROR; // 读取输入参数失败，返回错误码
    }

    if (m <= 0 || n <= 0 || t1 < 0 || t2 < 0)
    {
        return ERROR; // 参数不合法，返回错误码
    }

    Element *A = (Element *)malloc(t1 * sizeof(Element)); // 为矩阵A分配内存
    Element *B = (Element *)malloc(t2 * sizeof(Element)); // 为矩阵B分配内存

    read_sparse_matrix(A, t1); // 读取矩阵A的值
    read_sparse_matrix(B, t2); // 读取矩阵B的值

    sparse_matrix_addition(A, B, t1, t2); // 对矩阵A和矩阵B进行相加操作

    free_matrix(A); // 释放矩阵A的内存
    free_matrix(B); // 释放矩阵B的内存

    return 0; // 程序正常结束
}