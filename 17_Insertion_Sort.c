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

void insertionSort(int *a, int n)
{

    int key, j;
    for (int i = 0; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        // For ascen order use '>' and desc order use '<'
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int a[] = {1, 4, 76, 77, 5, 100, 70};
    int b[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    // Before sorting
    printArray(a, n);
    // After bubble sorting
    insertionSort(a, n);
    // After bubble sorting
    // AdaptiveBubbleSort(b, n);
    printArray(a, n);
    return 0;
}