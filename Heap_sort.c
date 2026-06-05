#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int temp;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

int main()
{
    int a[100000], b[100000], n;
    int values[5] = {100, 500, 1000, 2000, 3000};

    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    heapsort(a, n);

    printf("\nSorted elements:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n\nN\tTime(ms)\n");

    for (int i = 0; i < 5; i++)
    {
        n = values[i];

        for (int j = 0; j < n; j++)
            a[j] = rand() % 10000;

        start = clock();

        for (int k = 0; k < 500; k++)
        {
            for (int j = 0; j < n; j++)
                b[j] = a[j];

            heapsort(b, n);
        }

        end = clock();

        time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        printf("%d\t%.2f\n", n, time_taken);
    }

    return 0;
}
