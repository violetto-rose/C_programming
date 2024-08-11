// Design and implement C Program to solve discrete Knapsack and continuous Knapsack problems using greedy approximation method.

/*
Items Sorting: Items are sorted by their value-to-weight ratio.

Greedy Knapsack Function:
Handles both Fractional and Discrete knapsack based on the isFractional flag.
If isFractional is 1, it allows taking fractions of items.
If isFractional is 0, it only allows entire items.

Main Function:
Calls the greedy knapsack function twice: once for the Discrete Knapsack and once for the Fractional Knapsack.
*/

#include <stdio.h>

#define MAX 100

typedef struct
{
    int value;
    int weight;
    float ratio;
} Item;

void greedyKnapsack(int W, Item items[], int n, int isFractional)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (items[i].ratio < items[j].ratio)
            {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    float totalValue = 0;
    for (int i = 0; i < n && W > 0; i++)
    {
        if (items[i].weight <= W)
        {
            W -= items[i].weight;
            totalValue += items[i].value;
        }
        else if (isFractional)
        {
            totalValue += items[i].value * ((float)W / items[i].weight);
            break;
        }
    }

    printf("Maximum value in Knapsack = %.2f\n", totalValue);
}

int main()
{
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int W = 50; // Maximum weight capacity of the knapsack

    for (int i = 0; i < n; i++)
    {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    // Call for Discrete Knapsack (0/1 Knapsack)
    printf("Discrete Knapsack:\n");
    greedyKnapsack(W, items, n, 0);

    // Call for Fractional Knapsack
    printf("Fractional Knapsack:\n");
    greedyKnapsack(W, items, n, 1);

    return 0;
}
