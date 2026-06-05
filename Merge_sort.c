#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int b[100000];

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= mid)
        b[k++] = a[i++];

    while (j <= high)
        b[k++] = a[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = b[k];
}

void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int a[100000], n;
    int values[5] = {100, 500, 1000, 2000, 3000};

    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergesort(a, 0, n - 1);

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
        mergesort(a, 0, n - 1);
        end = clock();

        time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        printf("%d\t%.2f\n", n, time_taken);
    }

    return 0;
}
