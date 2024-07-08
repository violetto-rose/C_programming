// Design and implement C Program to solve discrete Knapsack and continuous Knapsack problems using greedy approximation method.
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    int weight;
    float ratio;
} Item;

int compare(const void *a, const void *b)
{
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    return (itemB->ratio > itemA->ratio) - (itemB->ratio < itemA->ratio);
}

void knapsack(int capacity, Item items[], int n)
{
    qsort(items, n, sizeof(Item), compare);

    int totalWeight = 0;
    int totalValue = 0;

    printf("Items taken into the knapsack:\n");
    for (int i = 0; i < n; i++)
    {
        if (totalWeight + items[i].weight <= capacity)
        {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item %d - Value: %d, Weight: %d\n", i + 1, items[i].value, items[i].weight);
        }
    }
    printf("Total weight: %d\n", totalWeight);
    printf("Total value: %d\n", totalValue);
}

int main()
{
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    Item *items = (Item *)malloc(n * sizeof(Item));
    if (items == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    knapsack(capacity, items, n);

    free(items);
    return 0;
}
