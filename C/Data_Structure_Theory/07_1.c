// 基于邻接表结构的DFS
// 使用算法时候无需对搜索进行递归调用

#include <stdio.h>
#include <stdlib.h>

// 定义邻接表中的结点
typedef struct Node
{
    int vertex;        // 顶点
    struct Node *next; // 指向下一个邻接结点的指针
} Node;

// 定义图
typedef struct Graph
{
    int numVertices; // 顶点数目
    Node **adjLists; // 邻接表数组
} Graph;             // 图的结构

// 创建图
// 传入参数是图的顶点数目
Graph *createGraph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    // 申请空间并初始化
    graph->numVertices = numVertices;
    graph->adjLists = (Node **)malloc(numVertices * sizeof(Node *));

    for (int i = 0; i < numVertices; i++)
    {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// 添加边
// 在图中添加一条从src到dest的边
// 传入参数：图、源顶点src、目标顶点dest
void addEdge(Graph *graph, int src, int dest)
{
    // 创建新结点
    // 为目标顶点dest创建一个新的邻接结点，并将其添加到源顶点src的邻接表中
    Node *newNode = (Node *)malloc(sizeof(Node));
    // 指向下一个邻接结点的指针指向NULL
    newNode->vertex = dest;
    // 将新结点添加到源顶点src的邻接表中
    newNode->next = graph->adjLists[src];
    // 将新结点的指针指向源顶点src的邻接表中
    graph->adjLists[src] = newNode;
}

// 深度优先搜索
// 传入参数：图、起始顶点startVertex、目标顶点targetVertex、访问过的顶点数组visited
int DFS(Graph *graph, int startVertex, int targetVertex, int *visited)
{
    if (startVertex == targetVertex)
    {
        return 1;
    }

    visited[startVertex] = 1;
    // 获取起始顶点对应的邻接表指针
    Node *adjList = graph->adjLists[startVertex];
    // 遍历当前顶点的邻接表
    while (adjList != NULL)
    {
        // 获取当前邻接顶点的索引并命名为 connectedVertex。
        int connectedVertex = adjList->vertex;
        if (!visited[connectedVertex])
        {
            if (DFS(graph, connectedVertex, targetVertex, visited))
            {
                return 1;
            }
        }
        adjList = adjList->next;
        // 向下遍历邻接表，指向下一个邻接结点
    }

    return 0;
}

int main()
{
    int numVertices, numEdges;
    scanf("%d %d", &numVertices, &numEdges);

    // 创建图
    Graph *graph = createGraph(numVertices);
    // 此处的graph就是使用邻接表的结构进行存储

    // 读取顶点信息
    int *vertices = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++)
    {
        scanf("%d", &vertices[i]);
    }

    // 添加边
    for (int i = 0; i < numEdges; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // 读取待判别的顶点对
    int vi, vj;
    scanf("%d %d", &vi, &vj);

    // 初始化visited数组
    int *visited = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = 0;
    }

    // 判断是否存在路径
    int result = DFS(graph, vi, vj, visited);

    // 输出结果
    if (result)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    return 0;
}
