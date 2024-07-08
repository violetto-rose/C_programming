//Design and implement C Program to find a subset of a given set S = {sl , s2,.....,sn} of n positive integers whose sum is equal to a given positive integer d.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print a subset
void printSubset(int subset[], int size) {
    printf("Subset found: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

// Recursive function to find subsets
bool findSubset(int set[], int subset[], int n, int subsetSize, int total, int targetSum, int index) {
    if (total == targetSum) {
        printSubset(subset, subsetSize);
        return true;
    }
    if (index == n || total > targetSum) {
        return false;
    }
    
    // Include the current element in the subset and move to the next element
    subset[subsetSize] = set[index];
    if (findSubset(set, subset, n, subsetSize + 1, total + set[index], targetSum, index + 1)) {
        return true;
    }

    // Exclude the current element from the subset and move to the next element
    return findSubset(set, subset, n, subsetSize, total, targetSum, index + 1);
}

int main() {
    int n, d;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int *set = (int *)malloc(n * sizeof(int));
    if (set == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &d);

    int *subset = (int *)malloc(n * sizeof(int));
    if (subset == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(set);
        return 1;
    }

    if (!findSubset(set, subset, n, 0, 0, d, 0)) {
        printf("No subset found with the given sum.\n");
    }

    free(set);
    free(subset);
    return 0;
}
