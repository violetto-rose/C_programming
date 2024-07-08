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

void fractionalKnapsack(int capacity, Item items[], int n)
{
    qsort(items, n, sizeof(Item), compare);

    int totalWeight = 0;
    float totalValue = 0.0;

    printf("Items taken into the knapsack:\n");
    for (int i = 0; i < n; i++)
    {
        if (totalWeight + items[i].weight <= capacity)
        {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item %d - Value: %d, Weight: %d\n", i + 1, items[i].value, items[i].weight);
        }
        else
        {
            int remain = capacity - totalWeight;
            totalValue += items[i].value * ((float)remain / items[i].weight);
            printf("Item %d - Value: %.2f, Weight: %d (fractional)\n", i + 1, items[i].value * ((float)remain / items[i].weight), remain);
            totalWeight += remain;
            break;
        }
    }
    printf("Total weight: %d\n", totalWeight);
    printf("Total value: %.2f\n", totalValue);
}

int main()
{
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    Item *items = (Item *)malloc(n * sizeof(Item));
    for (int i = 0; i < n; i++)
    {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    fractionalKnapsack(capacity, items, n);
    return 0;
}
