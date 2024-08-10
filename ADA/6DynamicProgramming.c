// Design and implement C Program to solve 0/1 Knapsack problem using Dynamic Programming method.

/*
Problem:

You're given a knapsack with a maximum weight capacity W and n items, each with a weight wt[] and a value val[].
The goal is to determine the maximum value that can be obtained by selecting items such that their total weight does not exceed the knapsack's capacity.

Dynamic Programming Table (dp[][]):

dp[i][w] stores the maximum value that can be achieved with the first i items and a knapsack capacity w.
The table is filled using the following logic:
If the item is not included, the value remains the same as without that item (dp[i-1][w]).
If the item is included, the value is the maximum of including or excluding that item (val[i-1] + dp[i-1][w-wt[i-1]] vs. dp[i-1][w]).

Initialization:

If there are no items (i == 0) or the knapsack capacity is zero (w == 0), the maximum value is zero (dp[i][w] = 0).
Main Function:

The knapsack() function computes the maximum value that can be carried in the knapsack of capacity W.
*/

#include <stdio.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int W, int wt[], int val[], int n) {
    int dp[MAX][MAX];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("Maximum value in Knapsack = %d\n", dp[n][W]);
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50; // Maximum weight capacity of the knapsack
    int n = sizeof(val) / sizeof(val[0]);

    knapsack(W, wt, val, n);
    return 0;
}
