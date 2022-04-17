#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaring the queue
struct DeQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

// Is Empty
int isEmpty(struct DeQueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

// Original Queueu

// Checking if queue is full
int isFull(struct DeQueue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

// Inserting element at Rear
void enQueueR(struct DeQueue *q, int val)
{
    if (isFull(q))
    {
        printf("DeQueue is full");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

// DE Queue special

// Deleting element at First
int deQueueF(struct DeQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("DeQueue is empty");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

// Inserting element at First
void enQueueF(struct DeQueue *q, int val)
{
    if (isFull(q))
    {
        printf("DeQueue is full");
    }
    else
    {
        q->f--;
        q->arr[q->f] = val;
    }
}

// Deleting element at Rear
int deQueueR(struct DeQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("DeQueue is empty");
    }
    else
    {
        q->r--;
        a = q->arr[q->r];
    }
    return a;
}

// Main
int main()
{
    struct DeQueue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // EnDeQueue
    enQueueR(&q, 20);
    enQueueR(&q, 40);
    printf("DeQueuing element %d\n", deQueueF(&q));
    printf("DeQueuing element %d\n", deQueueF(&q));
    enQueueF(&q, 50);
    enQueueF(&q, 12);

    // DeQueue
    printf("DeQueuing element %d\n", deQueueR(&q));
    printf("DeQueuing element %d\n", deQueueR(&q));

    // Checks
    if (isEmpty(&q))
    {
        printf("DeQueue is empty");
    }
    if (isFull(&q))
    {
        printf("DeQueue is full");
    }

    return 0;
}