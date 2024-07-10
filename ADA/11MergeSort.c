// Design and implement C Program to sort a given set of n integer elements using Merge Sort method and compute its time complexity. Run the program for varied values of n> 5000, and record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read from a file or can be generated using the random number generator.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge two subarrays L and M into arr
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp arrays
    int L[n1], M[n2];

    // Copy data to temp arrays L[] and M[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        M[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of M[], if any
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two halves, sort them and merge them
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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

// Main function to run Merge Sort and measure time taken
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
        mergeSort(arr, 0, n - 1);
        clock_t end = clock();

        double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken to sort %d elements: %f seconds\n", n, timeTaken);

        free(arr);
    }

    return 0;
}
