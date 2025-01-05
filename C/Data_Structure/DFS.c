#include <stdio.h>
#include <math.h>

// 定义一个数组用于记录每一行皇后的列位置
int lie[100];

// 打印当前棋盘上的皇后布局
void print(int huanghou)
{
    for (int i = 1; i <= huanghou; i++)
    {
        printf("%d ", lie[i]); // 打印每一行皇后的列位置
    }
    printf("\n"); // 换行
}

// 判断在(hang, j)位置放置皇后是否合法
int jian(int hang, int j)
{
    int i = 1;
    while (i < hang)
    {
        if (lie[i] == j || abs(hang - i) == abs(j - lie[i]))
        {
            return 0; // 如果发现冲突，则返回0表示不合法
        }
        i++;
    }
    return 1; // 没有发现冲突，返回1表示合法
}

// 深度优先搜索的主体函数
void dfs(int hang, int huanghou)
{
    if (hang > huanghou)
    {
        print(huanghou); // 如果所有皇后都放置完毕，打印当前布局
    }
    else
    {
        for (int j = 1; j <= huanghou; j++)
        {
            if (jian(hang, j))
            {
                lie[hang] = j;           // 在当前行j列放置皇后
                dfs(hang + 1, huanghou); // 递归处理下一行
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n); // 读取用户输入的皇后数N
    dfs(1, n);       // 从第一行开始尝试放置皇后
    return 0;
}