#include <stdio.h>
#include <stdlib.h>

// Node Declaration
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void DoublyLinkedListTraversal(struct Node *head)
{
    struct Node *p = head;
    printf("Front Traversal in Doubly Linked List: \n");
    while (p->next != NULL)
    {
        printf("Element: %d \n", p->data);
        p = p->next;
    }
    printf("Element: %d \n", p->data);
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Dynamic memory allocation for the nodes in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link 1st and 2nd Nodes
    head->data = 4;
    head->next = second;
    head->prev = NULL;

    // Link 2nd and 3rd Nodes
    second->data = 3;
    second->next = third;
    second->prev = head;

    // Terminate the list after third Node
    third->data = 6;
    third->next = fourth;
    third->prev = second;

    fourth->data = 1;
    fourth->next = head;
    fourth->prev = third;

    printf("Linked List Before Insertion\n");
    DoublyLinkedListTraversal(head);

    return 0;
}