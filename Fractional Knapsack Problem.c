#include <stdio.h>

struct Item
{
    int weight, profit;
    float ratio;
};

int main()
{
    int n, i, j, capacity;
    float totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    printf("Enter weight and profit of each item:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &item[i].weight, &item[i].profit);
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    /* Sort items in descending order of profit/weight ratio */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (item[i].ratio < item[j].ratio)
            {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    printf("\nSelected Items:\n");

    for (i = 0; i < n; i++)
    {
        if (capacity >= item[i].weight)
        {
            capacity -= item[i].weight;
            totalProfit += item[i].profit;

            printf("Item %d fully selected\n", i + 1);
        }
        else
        {
            totalProfit += item[i].ratio * capacity;

            printf("Item %d partially selected\n", i + 1);
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}
