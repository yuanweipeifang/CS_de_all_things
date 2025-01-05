#include <stdio.h>
#include <stdlib.h>

#define MAX 1001
int m = 0, n = 0;
char grid[MAX][MAX];
int visited[MAX][MAX];

void DFS(int x, int y)
{
    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 'w' || visited[x][y])
    {
        return;
    }
    visited[x][y] = 1;
    DFS(x + 1, y);
    DFS(x - 1, y);
    DFS(x, y + 1);
    DFS(x, y - 1);
    return;
}

int main()
{
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf(" %c", &grid[i][j]);
            //! 这里必须要加入空格防止读取时误将空格当做一个字符读入
            visited[i][j] = 0;
        }
    }
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 'l' && !visited[i][j])
            {
                DFS(i, j);
                cnt++;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}