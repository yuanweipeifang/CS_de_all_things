#include <stdio.h>
#include <limits.h>

#define MAX_NODES 100 // 定义最大节点数
#define INF 10000     // 定义不可达的距离

// 找到未访问节点中距离最小的节点
// 找到未访问节点中距离最小的节点
int minDistance(int dist[], int visited[], int n)
{
    int min = INF; // 初始化最小距离为无穷大
    int min_index; // 用于记录最小距离的节点索引

    // 遍历所有节点
    for (int v = 0; v < n; v++)
    {
        // 如果节点未被访问且距离小于等于当前最小距离
        if (visited[v] == 0 && dist[v] <= min)
        {
            min = dist[v]; // 更新最小距离
            min_index = v; // 更新最小距离的节点索引
        }
    }

    return min_index; // 返回距离最小的节点的索引
}

// Dijkstra算法
void dijkstra(int graph[MAX_NODES][MAX_NODES], int n, int src)
{
    int dist[MAX_NODES];    // 记录从源到每个节点的最短距离
    int visited[MAX_NODES]; // 记录节点是否被访问

    // 初始化所有距离为无穷大，所有节点未访问
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    // 源节点到自身的距离为0
    dist[src] = 0;

    // 找到从源到所有节点的最短路径
    for (int count = 0; count < n - 1; count++)
    {
        // 选择未访问节点中距离最小的节点
        int u = minDistance(dist, visited, n);

        // 标记该节点为已访问
        visited[u] = 1;

        // 更新该节点的邻接节点的距离
        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // 输出结果
    for (int i = 0; i < n; i++)
        printf("%d\n", dist[i]);
}

int main()
{
    int n;
    scanf("%d", &n);

    int graph[MAX_NODES][MAX_NODES];

    // 输入图的邻接矩阵
    //! 注意：这里的输入是无向图，所以需要对称地输入
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    // 调用Dijkstra算法
    dijkstra(graph, n, 0);

    return 0;
}
