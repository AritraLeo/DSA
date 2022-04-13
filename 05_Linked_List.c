#include <stdio.h>
#include <stdlib.h>

// Node Declaration
struct Node
{
    int data;
    struct Node *next;
};

// Traversal
void LinkedListTraversal(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("The Value is: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Insertion at the begenning
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// Insertion at given index
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != (index - 1))
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Inserting at the end of the List
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Insertion after a Node
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

// Deleting the first Node
struct Node *deleteAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Deleting at given index
struct Node *deleteAtIndex(struct Node *head, int index)
{

    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// Deleting the last Node
struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    return head;
}

// Deleting after a Node of given value Present at the lowest index in the List
struct Node *deleteAfterNode(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }

    return head;
}

// Main
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Dynamic memory allocation for the nodes in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link 1st and 2nd Nodes
    head->data = 7;
    head->next = second;

    // Link 2nd and 3rd Nodes
    second->data = 11;
    second->next = third;

    // Terminate the list after third Node
    third->data = 66;
    third->next = NULL;

    printf("Linked List Before Insertion\n");
    LinkedListTraversal(head);

    // printf("Linked List After Insertion\n");

    /* Insertions

    // Call when inserting at begening:
    // head = insertAtFirst(head, 100);

    // Call when inserting at index:
    // head = insertAtIndex(head, 100, 1);

    // Call when inserting at end:
    // head = insertAtEnd(head, 100);

    // Call when inserting after a Node
    // head =insertAfterNode(head, second, 100);
    */

    //

    /* Deletions */

    printf("Linked List After Deletion:\n");

    // Call when deleting at begening:
    // head = deleteAtFirst(head);

    // Call when inserting at index:
    // head = deleteAtIndex(head, 1);

    // Call when inserting at end:
    // head = deleteAtEnd(head);

    // Call when inserting after a Node
    head = deleteAfterNode(head, 11);

    LinkedListTraversal(head);

    return 0;
}
