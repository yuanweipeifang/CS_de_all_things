#include <stdio.h>
#include <limits.h>

#define MAX_NODES 100
#define INF 10000

// 找到未访问节点中距离最小的节点
// 通过比较距离数组和访问数组来找到未访问节点中距离最小的节点
int minDistance(int dist[], int visited[], int n)
{
	// 初始化最小距离和最小距离对应的节点
	int min = INF, min_index;

	// 遍历节点，找到未访问节点中距离最小的节点
	for (int v = 0; v < n; v++)
		if (visited[v] == 0 && dist[v] <= min)
		{
			min = dist[v];
			min_index = v;
		}

	// 返回找到的最小距离对应的节点
	return min_index;
}
// Dijkstra算法
// 使用Dijkstra算法计算图中从指定源节点到其他节点的最短路径
void dijkstra(int graph[MAX_NODES][MAX_NODES], int n, int src, int dist[], int prev[])
{
	int visited[MAX_NODES]; // 标记节点是否被访问过

	// 初始化距离数组、访问数组和前驱数组
	for (int i = 0; i < n; i++)
	{
		dist[i] = INF;	// 距离数组初始化为无穷大
		visited[i] = 0; // 访问数组初始化为未访问
		prev[i] = -1;	// 前驱数组初始化为-1
	}

	dist[src] = 0; // 设置起始节点的距离为0

	// 计算从源节点到其他各节点的最短路径
	for (int count = 0; count < n - 1; count++)
	{
		int u = minDistance(dist, visited, n); // 选择当前距离最小且未访问过的节点
		visited[u] = 1;						   // 标记该节点为已访问

		// 更新当前节点相邻节点的距离和前驱节点
		for (int v = 0; v < n; v++)
			if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
			{
				dist[v] = dist[u] + graph[u][v]; // 更新距离
				prev[v] = u;					 // 更新前驱节点
			}
	}
}

// 输出从src到dest的路径
void printPath(int prev[], int dest)
{
	if (prev[dest] == -1)
	{
		printf("%d\n", dest);
		return;
	}

	printPath(prev, prev[dest]);
	printf("%d\n", dest);
}

int main()
{
	int n;
	scanf("%d", &n); // 读取节点数

	int graph[MAX_NODES][MAX_NODES];
	// 读取表示图的邻接矩阵
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);

	int src, dest;
	scanf("%d %d", &src, &dest); // 读取源节点和目标节点

	int dist[MAX_NODES]; // 用于存储从源节点到各节点的最短距离的数组
	int prev[MAX_NODES]; // 用于存储最短路径中各节点的前驱节点的数组

	dijkstra(graph, n, src, dist, prev); // Dijkstra 算法

	printPath(prev, dest); // 打印从源节点到目标节点的最短路径

	return 0;
}

/*
我望着你，不肯后退的眼睛
输入：题目的样例如下，其中图的邻接矩阵表示如下：
			| 节点0 | 节点1 | 节点2 | 节点3 |
	| 节点0 | 0     | 2     | 10   | 10000 |
	| 节点1 | 2     | 0     | 7    | 3     |
	| 节点2 | 10    | 7     | 0    | 6     |
	| 节点3 | 10000 | 3     | 6    | 0     |
	开始
  |
  v
读取节点数n
  |
  v
初始化图的邻接矩阵
  |
  v
读取源节点src和目标节点dest
  |
  v
初始化Dijkstra算法
  |
  v
Dijkstra算法主循环
  |
  v
调用minDistance函数
  |
  v
找到未访问节点中距离最小的节点u
  |
  v
标记u为已访问
  |
  v
更新u的邻接节点的距离和前驱节点
  |
  v
输出最短路径
  |
  v
调用printPath函数
  |
  v
递归打印路径
  |
  v
结束

*/