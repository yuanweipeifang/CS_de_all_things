/*
以邻接表为存储结构实现求从源点到其他各顶点
的最短路径的迪杰斯特拉算法，用C程序编写
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 1000

// 邻接表中的边结点
typedef struct EdgeNode
{
    int dest;              // 目标顶点
    int weight;            // 边的权重
    struct EdgeNode *next; // 指向下一条边的指针
} EdgeNode;

// 邻接表中的顶点结点
typedef struct VertexNode
{
    EdgeNode *head; // 指向第一条边的指针
} VertexNode;

// 图的结构体
typedef struct Graph
{
    int numVertices;                   // 顶点数
    VertexNode vertices[MAX_VERTICES]; // 邻接表
} Graph;

// 创建图
Graph *createGraph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++)
    {
        graph->vertices[i].head = NULL;
    }
    return graph;
}

// 添加边
void addEdge(Graph *graph, int src, int dest, int weight)
{
    // 创建新的边结点
    EdgeNode *newNode = (EdgeNode *)malloc(sizeof(EdgeNode));
    newNode->dest = dest;                      // 设置目标顶点
    newNode->weight = weight;                  // 设置边的权重
    newNode->next = graph->vertices[src].head; // 将新结点的下一个指针指向当前顶点的第一条边
    graph->vertices[src].head = newNode;       // 更新当前顶点的第一条边为新结点
}

// 迪杰斯特拉算法
void dijkstra(Graph *graph, int src)
{
    int numVertices = graph->numVertices;
    int dist[MAX_VERTICES];    // 存储源点到各顶点的最短距离
    int visited[MAX_VERTICES]; // 记录顶点是否已被访问
    int parent[MAX_VERTICES];  // 存储最短路径上的父节点

    // 初始化
    for (int i = 0; i < numVertices; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[src] = 0;

    // 找到最短路径
    for (int count = 0; count < numVertices - 1; count++)
    {
        int minDist = INT_MAX;
        int minIndex = -1;

        // 选择未访问的顶点中距离最小的顶点
        for (int v = 0; v < numVertices; v++)
        {
            if (!visited[v] && dist[v] < minDist)
            {
                minDist = dist[v];//将最小的距离进行粘贴
                minIndex = v;
            }
        }

        // 标记该顶点为已访问
        visited[minIndex] = 1;

        // 更新与该顶点相邻的顶点的最短距离
        EdgeNode *curr = graph->vertices[minIndex].head;
        while (curr != NULL)
        {
            int dest = curr->dest;
            int weight = curr->weight;
            if (!visited[dest] && dist[minIndex] != INT_MAX && dist[minIndex] + weight < dist[dest])
            {
                dist[dest] = dist[minIndex] + weight;//!借助临时变量进行更新
                parent[dest] = minIndex;
            }
            curr = curr->next;
        }
    }

    // 打印最短路径和距离
    for (int i = 0; i < numVertices; i++)
    {
        printf("从顶点 %d 到顶点 %d 的最短路径为：", src, i);
        int j = i;
        while (j != src)
        {
            printf("%d <- ", j);
            j = parent[j];
        }
        printf("%d，距离为 %d\n", src, dist[i]);
    }
}

int main()
{
    int numVertices, numEdges;
    printf("请输入顶点数和边数：\n");
    scanf("%d %d", &numVertices, &numEdges);

    Graph *graph = createGraph(numVertices);

    printf("请输入边的信息（起点 终点 权重）：\n");
    for (int i = 0; i < numEdges; i++)
    {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    int src;
    printf("请输入源点：");
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}
