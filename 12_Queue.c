#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is full");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Enqueue
    enqueue(&q, 12);
    enqueue(&q, 20);

    // Dqueue
    printf("DeQueuing element %d", dequeue(&q));

    // Checks
    if (isEmpty(&q))
    {
        printf("Queue is empty");
    }
    if (isFull(&q))
    {
        printf("Queue is full");
    }

    return 0;
}