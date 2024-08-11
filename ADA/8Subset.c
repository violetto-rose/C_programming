// Design and implement C Program to find a subset of a given set S = {sl , s2,.....,sn} of n positive integers whose sum is equal to a given positive integer d.

/*
Function findSubset:

Base Case: If the target sum d is 0, print the current subset and return true.
Stopping Case: If no elements are left (n == 0) or the sum becomes negative (d < 0), return false.
Recursive Calls:
Include Last Element: Recursively try to find a subset that includes the current last element.
Exclude Last Element: Recursively try to find a subset that does not include the current last element.

Main Function:

Initializes the set S, target sum d, and a temporary subset array.
Calls findSubset to find and print a valid subset. If no subset is found, prints a message.
*/

#include <stdio.h>
#include <stdbool.h>

bool findSubset(int S[], int n, int d, int subset[], int subsetSize) {
    if (d == 0) {
        printf("Subset found: ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return true;
    }
    if (n == 0 || d < 0) return false;

    subset[subsetSize] = S[n - 1];
    if (findSubset(S, n - 1, d - S[n - 1], subset, subsetSize + 1)) return true;
    return findSubset(S, n - 1, d, subset, subsetSize);
}

int main() {
    int S[] = {3, 34, 4, 12, 5, 2};
    int d = 9;
    int n = sizeof(S) / sizeof(S[0]);
    int subset[n];

    if (!findSubset(S, n, d, subset, 0)) {
        printf("No subset with sum %d\n", d);
    }

    return 0;
}