#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define INF 10000

void floydWarshall(int graph[MAX_NODES][MAX_NODES], int n, int dist[MAX_NODES][MAX_NODES], int next[MAX_NODES][MAX_NODES])
{
    // graph参数为邻接矩阵，n为顶点个数，dist为距离矩阵，next为下一跳顶点矩阵

    // 初始化距离矩阵和路径矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = graph[i][j];
            if (graph[i][j] != INF && i != j)
                next[i][j] = j; // 如果顶点i和顶点j直接相连，则下一跳为j
            else
                next[i][j] = -1; // 否则下一跳为-1
        }
    }

    // 弗洛伊德算法
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j]; // 更新顶点i到顶点j的最短距离
                    next[i][j] = next[i][k];              // 更新顶点i到顶点j的下一跳顶点
                }
            }
        }
    }
}

// 打印路径
void printPath(int next[MAX_NODES][MAX_NODES], int u, int v)
{
    if (next[u][v] == -1)
    {
        return;
    }
    printf("%d\n", u);
    while (u != v)
    {
        u = next[u][v];
        printf("%d\n", u);
    }
}

// 主函数
int main()
{
    int n;
    scanf("%d", &n);

    // 二维数组 graph 用于存储图的邻接矩阵
    int graph[MAX_NODES][MAX_NODES];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // 二维数组 dist 和 next 用于存储 Floyd-Warshall 算法计算后的最短路径和路径信息
    int dist[MAX_NODES][MAX_NODES], next[MAX_NODES][MAX_NODES];
    floydWarshall(graph, n, dist, next);

    int m;
    scanf("%d", &m);

    // 对于 m 组输入，分别计算并输出对应两点之间的最短路径
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        printPath(next, u, v);
    }

    return 0;
}