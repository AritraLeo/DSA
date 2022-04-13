#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    /* data */
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d \n", (a->ptr)[i]);
    }
}

void setVal(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the element at %d \t", (i + 1));
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

int main()
{

    struct myArray marks;
    createArray(&marks, 10, 2);
    printf("Enter Value function is being enabled \n");
    setVal(&marks);
    printf("Enter Show function is being enabled \n");
    show(&marks);
    return 0;
}
