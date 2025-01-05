#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// 邻接表中的节点结构
typedef struct Node
{
    int vertex;        // 邻接顶点的编号
    struct Node *next; // 指向下一个邻接节点的指针
} Node;

// 图的邻接表结构
typedef struct Graph
{
    int numVertices;             // 顶点数
    int numEdges;                // 边数
    Node *adjList[MAX_VERTICES]; // 存储每个顶点的邻接顶点的指针数组
} Graph;

// 创建图的邻接表
/*
    先申请一段头结点的动态内存，再把图的顶点数和边数通过形参传递进来，然后再
    把邻接表的所有节点初始化为空
*/
Graph *createGraph(int numVertices, int numEdges)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;

    // 初始化邻接表为空
    for (int i = 0; i < numVertices; i++)
    {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// 添加边到图的邻接表
// src是边的起始顶点,dest是边的目标顶点
void addEdge(Graph *graph, int src, int dest)
{
    // 创建新的节点
    Node *newNode = (Node *)malloc(sizeof(Node));
    /*
    将目标顶点的编号赋值给newNode->vertex，
    将起始顶点的邻接链表的头指针赋值给newNode->next，
    这样新节点就指向了起始顶点的邻接链表的头部。*/
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];

    // 将新节点插入到邻接表的头部
    graph->adjList[src] = newNode;
}

// 广度优先搜索算法
int BFS(Graph *graph, int startVertex, int endVertex)
{
    // 此处注意对于局部变量一定要进行初始化
    int visited[MAX_VERTICES] = {0}; // 记录顶点是否被访问过
    int queue[MAX_VERTICES];         // 用于存储待访问的顶点
    int front = 0, rear = 0;         // 队列的前后指针

    visited[startVertex] = 1;    // 标记起始顶点为已访问
    queue[rear++] = startVertex; // 将起始顶点加入队列

    while (front < rear)
    {
        int currentVertex = queue[front++];         // 取出队列中的顶点
        Node *temp = graph->adjList[currentVertex]; // 获取当前顶点的邻接链表

        while (temp)
        {
            int adjVertex = temp->vertex; // 获取邻接顶点的编号

            if (adjVertex == endVertex)
            {
                return 1; // 如果找到目标顶点，返回1表示存在路径
            }

            if (!visited[adjVertex])
            {
                visited[adjVertex] = 1;    // 标记邻接顶点为已访问
                queue[rear++] = adjVertex; // 将邻接顶点加入队列
            }

            temp = temp->next; // 继续遍历下一个邻接顶点
        }
    }

    return 0; // 没有找到路径，返回0表示不存在路径
}

int main()
{
    int numVertices, numEdges;
    scanf("%d %d", &numVertices, &numEdges);
    // 输入节点和边的数量

    Graph *graph = createGraph(numVertices, numEdges);

    // 读取顶点信息，但没有使用
    for (int i = 0; i < numVertices; i++)
    {
        int vertex;
        scanf("%d", &vertex);
    }

    // 读取边信息，构建邻接表
    for (int i = 0; i < numEdges; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest); // 每读取一次就把边加入到邻接表当中
    }

    // 此处输入待判断的节点
    int startVertex, endVertex;
    scanf("%d %d", &startVertex, &endVertex);

    int result = BFS(graph, startVertex, endVertex);

    // 输出结果即可
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
