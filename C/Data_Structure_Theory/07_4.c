// 迪杰斯特拉算法的实现
#include <stdio.h>
#include <stdlib.h>

#define MAX 108
#define MAXINT 1000

typedef struct Node
{
    int adjvex;
    int weight;
    struct Node *nextarc;
} Node;

typedef struct Vnode
{
    int data;
    struct Node *firstarc;
} Vnode, AdjList[MAX];

typedef struct ALGraph
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

int visited[MAX];
int dist[MAX];

ALGraph create(int n, int m)
{
    ALGraph G;
    G.vexnum = n;
    G.arcnum = m;
    for (int i = 1; i <= n; i++)
    {
        G.vertices[i].data = i;
        G.vertices[i].firstarc = NULL;
    }
    for (int i = 1; i <= m; i++)
    {
        int a, adjvex, quan;
        Node *p = (Node *)malloc(sizeof(Node));
        scanf("%d %d %d", &a, &adjvex, &quan);
        p->adjvex = adjvex;
        p->weight = quan;
        p->nextarc = G.vertices[a].firstarc;
        G.vertices[a].firstarc = p;
    }
    return G;
}

void Dijkstra(ALGraph G, int n)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = MAXINT;
        visited[i] = 0;
    }
    dist[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        int temp = MAXINT;
        int u = -1;

        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && dist[j] < temp)
            {
                u = j;
                temp = dist[j];
            }
        }

        if (u == -1)
            break; // All reachable nodes processed

        visited[u] = 1;
        Node *p = G.vertices[u].firstarc;
        while (p)
        {
            if (!visited[p->adjvex] && dist[u] + p->weight < dist[p->adjvex])
            {
                dist[p->adjvex] = dist[u] + p->weight;
            }
            p = p->nextarc;
        }
    }
}

void print(ALGraph G, int n)
{
    int flag[MAX] = {0};
    for (int i = 2; i <= n; i++)
    {
        int temp = MAXINT + 1, u = -1;
        for (int j = 2; j <= n; j++)
        {
            if (!flag[j] && dist[j] < temp)
            {
                temp = dist[j];
                u = j;
            }
        }
        flag[u] = 1;
        if (dist[u] != MAXINT)
            printf("1 %d %d\n", u, dist[u]);
        else
            printf("1 %d -1\n", u);
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    ALGraph G = create(n, m);
    Dijkstra(G, n);
    print(G, n);
    return 0;
}
