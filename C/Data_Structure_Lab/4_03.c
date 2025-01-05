#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define INF 10000

// 弗洛伊德算法实现全点对最短路径
void floydWarshall(int graph[MAX_NODES][MAX_NODES], int n, int dist[MAX_NODES][MAX_NODES])
{
    // graph[i][j]表示从i到j的距离
    // n表示节点个数
    // dist[i][j]表示从i到j的最短路径距离
    // 初始化距离矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = graph[i][j];
            // 使用输入的图的邻接矩阵初始化距离矩阵
        }
    }

    // 弗洛伊德算法
    // k表示中间节点
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    // 更新最短路径
                }
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    /* 定义二维数组 graph 用于存储图的邻接矩阵 */
    int graph[MAX_NODES][MAX_NODES];
    /* 循环读取图的邻接矩阵，并存储到二维数组 graph 中 */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    /* 定义二维数组 dist 用于存储节点对之间的最短路径距离 */
    int dist[MAX_NODES][MAX_NODES];
    floydWarshall(graph, n, dist);

    /* 定义变量 m 用于存储查询次数 */
    int m;
    scanf("%d", &m);

    /* 循环进行查询操作 */
    for (int i = 0; i < m; i++)
    {
        /* 定义变量 u 和 v 用于存储查询的节点对 */
        int u, v;
        /* 从标准输入读取节点对，并输出它们之间的最短路径距离 */
        scanf("%d %d", &u, &v);
        printf("%d\n", dist[u][v]);
    }

    return 0;
}
