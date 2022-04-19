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

void bubbleSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void AdaptiveBubbleSort(int *b, int n)
{
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        printf("Working on pass No. %d \n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                int temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
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
    // bubbleSort(a, n);
    // After bubble sorting
    AdaptiveBubbleSort(b, n);
    printArray(a, n);
    return 0;
}
