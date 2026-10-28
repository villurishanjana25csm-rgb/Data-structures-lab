#include <stdio.h>

#define MAX 20
#define INF 10000000

int d[MAX][MAX];
int n;

/* Floyd-Warshall Algorithm */
void floydWarshall()
{
    int i, j, k;

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (d[i][k] != INF && d[k][j] != INF &&
                    d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

/* Display Distance Matrix */
void displayMatrix()
{
    int i, j;

    printf("\nAll-Pairs Shortest Distance Matrix:\n\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (d[i][j] == INF)
                printf("%8s", "INF");
            else
                printf("%8d", d[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int i, j;

    printf("Enter number of vertices (1-%d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    printf("\nEnter the cost adjacency matrix:\n");
    printf("Enter %d for INF (no direct edge).\n", INF);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &d[i][j]);
        }
    }

    floydWarshall();
    displayMatrix();

    return 0;
}
