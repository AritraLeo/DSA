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

// Merging elements of an array

void merge(int a[], int low, int mid, int high)
{
    int i, j, k, b[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        // Copying from b to a to print
        a[i] = b[i];
    }
}

// Merge Sort
void mergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

// main
int main()
{
    int a[] = {1, 4, 76, 77, 5, 100, 70};
    int n = 7;
    int low = 0, high = n - 1;
    // Before sorting
    printArray(a, n);

    mergeSort(a, low, high);
    // After selection sorting
    printArray(a, n);
    return 0;
}
