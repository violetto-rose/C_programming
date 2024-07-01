#include <stdio.h>
#define max 100

void comparecountsort(int* array, int* countarray, int* sortedarray, int size);

int main()
{
    int arr[max], count[max], sort[max], size, i;
    printf("Enter the size of array:\n");
    scanf("%d", &size);
    printf("Enter the elements of array:\n");
    for(i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    for(i = 0; i < size; i++)
        count[i] = 0;
    comparecountsort(arr, count, sort, size);
    printf("The sorted array is:\n");
    for(i = 0; i < size; i++)
        printf("%d, ", sort[i]);
    printf("\n");
    return 0;
}

void comparecountsort(int* array, int* countarray, int* sortedarray, int size)
{
    int i, j;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(array[i] <= array[j])
                countarray[i]++;
            else
                countarray[j]++;
        }
    }
    for(i = 0; i < size ; i++)
        sortedarray[countarray[i]] = array[i];
}