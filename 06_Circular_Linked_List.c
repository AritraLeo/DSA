#include <stdio.h>
#include <stdlib.h>

// Node Declaration
struct Node
{
    int data;
    struct Node *next;
};

// Traversal
void CircularLinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    /* Method - 1
    int c = 1;
    while (c != 2)
    {
        printf("The Value is: %d\n", ptr->data);
        ptr = ptr->next;
        if (ptr == head)
        {
            c++;
        }
    }*/

    // Method 2
    do
    {
        printf("The Value is: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);

    printf("\n");
}

// Insertion at the begenning:
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
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

    // Link 2nd and 3rd Nodes
    second->data = 3;
    second->next = third;

    // Terminate the list after third Node
    third->data = 6;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = head;

    printf("Linked List Before Insertion\n");
    CircularLinkedListTraversal(head);

    printf("Linked List After Insertion\n");

    /* Insertions */

    // Call when inserting at begening:

    // head = insertAtFirst(head, 100);
    // CircularLinkedListTraversal(head);

    return 0;
}
