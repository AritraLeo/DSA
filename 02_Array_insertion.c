#include<stdio.h>

void input(int a[], int n){
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void display(int a[], int n) {

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}

void indexInsert(int a[], int size, int capacity, int element, int indexAt) {

    if (size > capacity)
    {
        printf("Wrong !");
    }
    else
    {
        
    
    for (int i = size-1; i >= indexAt; i--)
    {
        a[i+1] = a[i];
    }
    a[indexAt] = element;
    }
}

int main(){

    int n, total_size=10, element, indexAt;
    printf("Enter the length of array:");
    scanf("%d", &n);
    int arr[total_size];
    // Taking input:
    printf("Enter the elements of array:");
    input(arr, n);
    // displaying input array:
    printf("Now displaying the elements of array: ");
    display(arr, n);
    // Inserting and displaying:
    printf("Enter the element to be inserted and at what position:\n");
    scanf("%d%d", &element, &indexAt);
    indexAt = indexAt - 1;
    indexInsert(arr, n, total_size, element, indexAt);
    n += 1;
    printf("Now displaying the array with the element inserted:\n");
    display(arr, n);
    return 0;
    
}

