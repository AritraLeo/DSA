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

void selectionSort(int *a, int n)
{

    int indexOfMin = 0;
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        // Swap
        int temp = a[i];
        a[i] = a[indexOfMin];
        a[indexOfMin] = temp;
    }
}

int main()
{
    int a[] = {1, 4, 76, 77, 5, 100, 70};
    int n = 7;
    // Before sorting
    printArray(a, n);

    selectionSort(a, n);
    // After selection sorting
    printArray(a, n);
    return 0;
}
