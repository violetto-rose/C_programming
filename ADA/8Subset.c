// Design and implement C Program to find a subset of a given set S = {sl , s2,.....,sn} of n positive integers whose sum is equal to a given positive integer d.

/*
Recursive Function (isSubsetSum):

Base Cases:
If sum is 0, then a subset with the desired sum has been found, so return 1 (true).
If n (number of elements) is 0 and the sum is not 0, then no such subset exists, so return 0 (false).
Exclude the Last Element: If the last element of the set is greater than sum, it can't be included in the subset, so check for the sum excluding this element.
Include or Exclude the Last Element: Check if a subset exists with or without including the last element of the set.

Main Function:

Defines a set of integers and the desired sum.
Calls isSubsetSum to determine if a subset exists with the given sum and prints the result.
*/

#include <stdio.h>

int isSubsetSum(int set[], int n, int sum) {
    if (sum == 0) return 1;
    if (n == 0 && sum != 0) return 0;

    if (set[n-1] > sum)
        return isSubsetSum(set, n-1, sum);

    return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);

    if (isSubsetSum(set, n, sum) == 1)
        printf("Found a subset with the given sum\n");
    else
        printf("No subset with the given sum\n");

    return 0;
}

