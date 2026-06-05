#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[1000][1000], visited[1000], stack[1000];
int top = -1, n;

void topo(int v)
{
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (a[v][i] && !visited[i])
            topo(i);
    }

    stack[++top] = v;
}

void reset()
{
    top = -1;

    for (int i = 0; i < n; i++)
        visited[i] = 0;
}

void generateGraph(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
                a[i][j] = rand() % 2;
            else
                a[i][j] = 0;
        }
    }
}

int main()
{
    clock_t start, end;
    double time_taken;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    reset();

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            topo(i);
    }

    printf("\nTopological Ordering:\n");
    while (top != -1)
        printf("%d ", stack[top--]);

    printf("\n\nVertices\tTime(ms)\n");

    for (n = 100; n <= 500; n += 100)
    {
        reset();
        generateGraph(n);

        start = clock();

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                topo(i);
        }

        end = clock();

        time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        printf("%d\t\t%.2f\n", n, time_taken);
    }

    return 0;
}
