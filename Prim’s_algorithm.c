#include <stdio.h>

#define INF 999

int main()
{
    int n, i, j, min, u = 0, v = 0, total = 0, edges = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n], visited[n];

    printf("Enter cost adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

        visited[i] = 0;
    }

    visited[0] = 1;

    printf("\nEdges in Minimum Cost Spanning Tree:\n");

    while (edges < n - 1)
    {
        min = INF;

        for (i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", u, v, min);

        total += min;
        visited[v] = 1;
        edges++;
    }

    printf("\nMinimum Cost = %d\n", total);

    return 0;
}
