#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", a[i]);
    }
    printf("\n");
}

int partition(int a[], int low, int high)
{
    int temp;
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    do
    {

        while (a[i] <= pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    } while (i < j);

    // Interchange low and j i.e pivot

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quickSort(int a[], int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(a, low, high);
        quickSort(a, low, partitionIndex - 1);  // Sorting left partition
        quickSort(a, partitionIndex + 1, high); // Sorting right partition
    }
}

int main()
{
    int a[] = {1, 4, 76, 77, 5, 100, 70};
    int n = 7;
    // Before sorting
    printArray(a, n);

    quickSort(a, 0, n - 1);
    // After selection sorting
    printArray(a, n);
    return 0;
}
