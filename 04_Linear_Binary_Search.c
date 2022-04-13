#include <stdio.h>

void input(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void display(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}

void linearSearch(int a[], int size, int element)
{

    for (int i = 0; i < size; i++)
    {
        if (a[i] = element)
        {
            printf("The array contains the element: %d\n", element);
            break;
        }
        else
            continue;
    }
}

void binarySearch(int a[], int size, int element)
{
    int low = 0, mid, high = size - 1, index = 0;
    //  Start Searching:

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == element)
        {
            index = mid;
            printf("The array contains the element: %d at %d\n", element, index);
            break;
        }

        if (a[mid] < element)
            low = mid + 1;

        else
            high = mid - 1;
    }

    printf("Element doesn't exist");
}

int main()
{
    int n, total_size, element, ch;
    printf("Enter the length of array:");
    scanf("%d", &n);
    int arr[total_size];

    // Taking input:
    printf("Enter the elements of array:");
    input(arr, n);

    // displaying input array:
    printf("Now displaying the elements of array: ");
    display(arr, n);

    // Enter the element to be searched:
    printf("Enter the element to be searched:\n");
    scanf("%d", &element);

    // To choose LS or BS:
    printf("Enter your choice 1 for LS or 2 for BS :");
    scanf("%d", &ch);

    if (ch == 1)
    {
        // Linea r Search
        linearSearch(arr, n, element);
    }
    else if (ch == 2)
    {
        binarySearch(arr, n, element);
    }
    else
    {
        printf("You're sick bro!");
    }

    return 0;
}
