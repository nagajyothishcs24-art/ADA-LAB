#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1, j = high, temp;

    while (1)
    {
        while (i <= high && a[i] <= pivot)
            i++;

        while (a[j] > pivot)
            j--;

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            break;
        }
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);

        quicksort(a, low, p - 1);
        quicksort(a, p + 1, high);
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

    quicksort(a, 0, n - 1);

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

            quicksort(b, 0, n - 1);
        }

        end = clock();

        time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        printf("%d\t%.2f\n", n, time_taken);
    }

    return 0;
}
