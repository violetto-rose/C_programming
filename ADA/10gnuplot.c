// Design and implement C Program to sort a given set of n integer elements using Quick Sort method and compute its time complexity. Run the program for varied values of n> 5000 and record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read from a file or can be generated using the random number generator.

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
// Function declarations
void fnGenRandInput(int[], int);
void fnDispArray(int[], int);
int fnPartition(int[], int, int);
void fnQuickSort(int[], int, int);
void fnSwap(int *, int *);
// Swap function
void fnSwap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int main(int argc, char **argv)
{
    FILE *fp;
    struct timeval tv;
    double dStart, dEnd;
    int iaArr[500000], iNum, i, iChoice;
    srand(time(NULL)); // Seed the random number generator once
    while (1)
    {
        printf("\n1. Plot the Graph\n2. QuickSort\n3. Exit");
        printf("\nEnter your choice\n");
        scanf("%d", &iChoice);
        switch (iChoice)
        {
        case 1:
            fp = fopen("QuickPlot.dat", "w");
            if (fp == NULL)
            {
                perror("Error opening file");
                return -1;
            }
            for (i = 100; i < 100000; i += 100)
            {
                fnGenRandInput(iaArr, i);
                gettimeofday(&tv, NULL);
                dStart = tv.tv_sec + (tv.tv_usec / 1000000.0);
                fnQuickSort(iaArr, 0, i - 1);
                gettimeofday(&tv, NULL);
                dEnd = tv.tv_sec + (tv.tv_usec / 1000000.0);
                fprintf(fp, "%d\t%lf\n", i, dEnd - dStart);
            }
            fclose(fp);
            printf("\nData File generated and stored in file <QuickPlot.dat>. Use a plotting utility\n");
            break;
        case 2:
            printf("\nEnter the number of elements to sort\n");
            scanf("%d", &iNum);
            printf("\nUnsorted Array\n");
            fnGenRandInput(iaArr, iNum);
            fnDispArray(iaArr, iNum);
            fnQuickSort(iaArr, 0, iNum - 1);
            printf("\nSorted Array\n");
            fnDispArray(iaArr, iNum);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
int fnPartition(int a[], int l, int r)
{
    int pivot = a[l];
    int i = l + 1;
    int j = r;
    while (1)
    {
        while (i <= r && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i >= j)
            break;
        fnSwap(&a[i], &a[j]);
    }
    fnSwap(&a[l], &a[j]);
    return j;
}
void fnQuickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int s = fnPartition(a, l, r);
        fnQuickSort(a, l, s - 1);
        fnQuickSort(a, s + 1, r);
    }
}
void fnGenRandInput(int X[], int n)
{
    for (int i = 0; i < n; i++)
    {
        X[i] = rand() % 10000;
    }
}
void fnDispArray(int X[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%5d\n", X[i]);
    }
}
