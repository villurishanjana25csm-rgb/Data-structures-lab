#include <stdio.h>

#define MAX 20

int n, adj[MAX][MAX], visited[MAX];

/* Breadth First Search */
void bfs(int s)
{
    int q[MAX], front = 0, rear = 0;
    int u, v;

    for (v = 0; v < n; v++)
        visited[v] = 0;

    visited[s] = 1;
    q[rear++] = s;

    while (front < rear)
    {
        u = q[front++];
        printf("%d ", u);

        for (v = 0; v < n; v++)
        {
            if (adj[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                q[rear++] = v;
            }
        }
    }
}

/* Depth First Search */
void dfs(int u)
{
    int v;

    visited[u] = 1;
    printf("%d ", u);

    for (v = 0; v < n; v++)
    {
        if (adj[u][v] == 1 && visited[v] == 0)
        {
            dfs(v);
        }
    }
}

int main()
{
    int i, j, s;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of cities!\n");
        return 1;
    }

    printf("Enter adjacency matrix (%d x %d):\n", n, n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting node (0 to %d): ", n - 1);
    scanf("%d", &s);

    if (s < 0 || s >= n)
    {
        printf("Invalid starting node!\n");
        return 1;
    }

    printf("\nNodes reachable using BFS: ");
    bfs(s);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nNodes reachable using DFS: ");
    dfs(s);

    printf("\n");

    return 0;
}
