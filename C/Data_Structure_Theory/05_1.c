#include <stdio.h>

// 函数声明：输入稀疏矩阵
void inputSparseMatrix(int S[][3], int t);

// 函数声明：稀疏矩阵相加
void addSparseMatrices(int S1[][3], int t1, int S2[][3], int t2, int S[][3], int *t);

int main()
{
    int t1, t2;
    scanf("%d %d", &t1, &t2);

    int S1[t1][3], S2[t2][3], S[t1 + t2][3];

    inputSparseMatrix(S1, t1);
    inputSparseMatrix(S2, t2);

    int t3 = 0; // 结果矩阵S的非零元素个数
    addSparseMatrices(S1, t1, S2, t2, S, &t3);

    for (int i = 0; i < t3; ++i)
    {
        printf("%d %d %d\n", S[i][0], S[i][1], S[i][2]);
    }

    return 0;
}

// 函数定义：输入稀疏矩阵
void inputSparseMatrix(int S[][3], int t)
{
    for (int i = 0; i < t; ++i)
    {
        scanf("%d %d %d", &S[i][0], &S[i][1], &S[i][2]);
    }
}

// 函数定义：稀疏矩阵相加
void addSparseMatrices(int S1[][3], int t1, int S2[][3], int t2, int S[][3], int *t)
{
    int h1 = 0, h2 = 0, h = 0;
    while (h1 < t1 && h2 < t2)
    {
        if (S1[h1][0] < S2[h2][0])
        {
            S[h][0] = S1[h1][0], S[h][1] = S1[h1][1], S[h][2] = S1[h1][2];
            ++h1;
        }
        else if (S1[h1][0] > S2[h2][0])
        {
            S[h][0] = S2[h2][0], S[h][1] = S2[h2][1], S[h][2] = S2[h2][2];
            ++h2;
        }
        else
        {
            if (S1[h1][1] < S2[h2][1])
            {
                S[h][0] = S1[h1][0], S[h][1] = S1[h1][1], S[h][2] = S1[h1][2];
                ++h1;
            }
            else if (S1[h1][1] > S2[h2][1])
            {
                S[h][0] = S2[h2][0], S[h][1] = S2[h2][1], S[h][2] = S2[h2][2];
                ++h2;
            }
            else
            {
                S[h][0] = S1[h1][0], S[h][1] = S1[h1][1], S[h][2] = S1[h1][2] + S2[h2][2];
                ++h1, ++h2;
            }
        }
        if (S[h][2] != 0)
            ++h;
    }
    *t = h; // 更新结果矩阵S的非零元素个数
}
