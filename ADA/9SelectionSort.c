// Design and implement C Program to sort a given set of n integer elements using Selection Sort method and compute its time complexity. Run the program for varied values of n> 5000 and record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read from a file or can be generated using the random number generator.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Selection Sort function
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

// Function to generate an array of random integers
void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000; // Random numbers between 0 and 9999
    }
}

// Main function to run Selection Sort and measure time taken
int main()
{
    srand(time(0));                                            // Seed for random number generator
    int nValues[] = {5000, 10000, 20000, 30000, 40000, 50000}; // Different n values
    int numTests = sizeof(nValues) / sizeof(nValues[0]);

    for (int i = 0; i < numTests; i++)
    {
        int n = nValues[i];
        int *arr = (int *)malloc(n * sizeof(int));
        generateRandomArray(arr, n);

        clock_t start = clock();
        selectionSort(arr, n);
        clock_t end = clock();

        double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken to sort %d elements: %f seconds\n", n, timeTaken);

        free(arr);
    }

    return 0;
}
