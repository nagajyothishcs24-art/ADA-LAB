#include <stdio.h>

#define INF 999

int main()
{
    int n, i, j, source, count, min, next;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n], dist[n], visited[n];

    printf("Enter cost adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for (i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;
    count = 1;

    while (count < n - 1)
    {
        min = INF;

        for (i = 0; i < n; i++)
        {
            if (dist[i] < min && !visited[i])
            {
                min = dist[i];
                next = i;
            }
        }

        visited[next] = 1;

        for (i = 0; i < n; i++)
        {
            if (!visited[i] && min + cost[next][i] < dist[i])
            {
                dist[i] = min + cost[next][i];
            }
        }

        count++;
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (i = 0; i < n; i++)
    {
        printf("%d -> %d = %d\n", source, i, dist[i]);
    }

    return 0;
}
