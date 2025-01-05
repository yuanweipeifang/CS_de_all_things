#include <stdio.h>

#define MAX 1001
int m = 0, n = 0;
char grid[MAX][MAX] = {0};
int visited[MAX][MAX] = {0};
int sum;

void DFS(int x, int y, int money)
{
    if (x > n - 1 || x < 0 || y > m - 1 || y < 0 || visited[x][y] == 1 || grid[x][y] == 0)
    {
        return;
    }
    money += grid[x][y];
    sum = sum < money ? money : sum;// 此处实际实现了对于路径权值的求和
    visited[x][y] = 1;
    // 向四个方向扩散进行实际的搜索法
    DFS(x + 1, y, money);
    DFS(x - 1, y, money);
    DFS(x, y + 1, money);
    DFS(x, y - 1, money);
    visited[x][y] = 0;
    //! 恢复未访问状态，以便其他路径访问,否则会默认将最优化路径的一部分省略
    //! 此处要特别特别注意！！！
    return;
}

int main()
{
    scanf("%d %d", &m, &n);
    // 输入地图的行数和列数
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &grid[i][j]);
            visited[i][j] = 0;
            // 此处将地图的权值输入其中，同时将访问的状态置0
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] > 0 && visited[i][j] == 0)
            //! 从未访问过的有金矿位置开始(这里注意容易出错)
            {
                DFS(i, j, 0);
                // 此处进行递归的深度优先搜索法
            }
        }
    }
    printf("%d", sum);
    return 0;
}