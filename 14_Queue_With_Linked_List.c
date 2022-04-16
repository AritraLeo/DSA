#include <stdio.h>
#include <stdlib.h>

// Declaring Global Variables
struct Node *f = NULL;
struct Node *r = NULL;

// Node Declaration
struct Node
{
    int data;
    struct Node *next;
};

// Traversal
void LinkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements\n");
    while (ptr != NULL)
    {
        printf("The Value is: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Enqueue
void enqueue(int val)
{

    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is full");
    }

    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

// Dequeue
int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if (f == NULL)
    {
        printf("Queue is empty");
    }

    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    LinkedListTraversal(f);
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    enqueue(40);
    LinkedListTraversal(f);

    return 0;
}
