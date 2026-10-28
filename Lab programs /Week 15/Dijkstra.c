#include <stdio.h>
#define MAX 20
#define INF 9999

int cost[MAX][MAX], n;

void dijkstra(int src, int dest)
{
    int dist[MAX], prev[MAX], visited[MAX];
    int i, j, u, min, path[MAX], len = 0;

    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        prev[i] = -1;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (i = 0; i < n; i++)
    {
        min = INF;
        u = -1;

        for (j = 0; j < n; j++)
            if (!visited[j] && dist[j] < min)
                min = dist[j], u = j;

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < n; j++)
            if (cost[u][j] > 0 && !visited[j] &&
                dist[u] + cost[u][j] < dist[j])
            {
                dist[j] = dist[u] + cost[u][j];
                prev[j] = u;
            }
    }

    if (dist[dest] == INF)
    {
        printf("No path exists.\n");
        return;
    }

    printf("Shortest distance = %d\n", dist[dest]);

    for (i = dest; i != -1; i = prev[i])
        path[len++] = i;

    printf("Path: ");
    for (i = len - 1; i >= 0; i--)
        printf("%d ", path[i]);

    printf("\n");
}

int main()
{
    int i, j, src, dest;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix (0 = no edge):\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter start node and end node: ");
    scanf("%d %d", &src, &dest);

    dijkstra(src, dest);

    return 0;
}
