// dijkstra.c
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 120
#define INFINITY 10000

typedef struct
{
    int vexNum;
    int graph[MAX_VERTICES][MAX_VERTICES];
} Graph;

typedef struct
{
    int flags[MAX_VERTICES];
    int stepN[MAX_VERTICES];
} Step;

void createGraph(Graph *g)
{
    int i, j;
    scanf("%d", &(g->vexNum));
    for (i = 0; i < g->vexNum; i++)
    {
        for (j = 0; j < g->vexNum; j++)
        {
            scanf("%d", &(g->graph[i][j]));
        }
    }
}

void clearStep(Step *s, Graph *g)
{
    for (int i = 0; i < g->vexNum; i++)
    {
        s->flags[i] = -1;
        s->stepN[i] = 0;
    }
}

void initializeStep(Step *s, Graph *g)
{
    for (int i = 0; i < g->vexNum; i++)
    {
        if (g->graph[0][i] != INFINITY)
        {
            s->flags[i] = 1;
            s->stepN[i] = g->graph[0][i];
        }
    }
}

int hasUnvisited(Step *s, Graph *g)
{
    for (int i = 1; i < g->vexNum; i++)
    {
        if (s->flags[i] == 1)
        {
            return 1;
        }
    }
    return 0;
}

int findMinStepN(Step *s, Graph *g)
{
    int min = INFINITY, n = -1;
    for (int i = 1; i < g->vexNum; i++)
    {
        if (s->flags[i] == 1 && s->stepN[i] < min)
        {
            min = s->stepN[i];
            n = i;
        }
    }
    return n;
}

void updateStepN(Step *s, Graph *g, int min)
{
    int minStepN = s->stepN[min];
    s->flags[min] = 0;
    for (int i = 0; i < g->vexNum; i++)
    {
        if (s->flags[i] == 1)
        {
            if (s->stepN[i] > g->graph[min][i] + minStepN)
            {
                s->stepN[i] = g->graph[min][i] + minStepN;
            }
        }
        else if (s->flags[i] == -1)
        {
            s->flags[i] = 1;
            s->stepN[i] = g->graph[min][i] + minStepN;
        }
    }
}

void dijkstra(Graph *g, Step *s)
{
    int min;
    clearStep(s, g);
    initializeStep(s, g);
    while (hasUnvisited(s, g))
    {
        min = findMinStepN(s, g);
        updateStepN(s, g, min);
    }
}

void printResult(Graph *g, Step *s)
{
    for (int i = 0; i < g->vexNum; i++)
    {
        printf("%d\n", s->stepN[i]);
    }
}

int main()
{
    Graph g;
    Step s;
    createGraph(&g);
    dijkstra(&g, &s);
    printResult(&g, &s);
    return 0;
}
