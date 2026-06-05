#include <stdio.h>

#define INF 999

int main()
{
    int n, i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int dist[n][n], graph[n][n];

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            dist[i][j] = graph[i][j];
        }
    }

    printf("\nGraph with Weights:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", graph[i][j]);

        printf("\n");
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printf("\nAll Pair Shortest Path Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", dist[i][j]);

        printf("\n");
    }

    return 0;
}
