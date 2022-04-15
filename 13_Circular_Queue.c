#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Circularqueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct Circularqueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Circularqueue *q)
{
    if ((q->r + 1) % (q->size) == q->f)
    {
        return 1;
    }
    return 0;
}

void enCircularqueue(struct Circularqueue *q, int val)
{
    if (isFull(q))
    {
        printf("Circularqueue is full");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("Enquing element %d\n", val);
    }
}

int deCircularqueue(struct Circularqueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Circularqueue is empty");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct Circularqueue q;
    // Size always less by 1 to capacity to store initial 0
    q.size = 5;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // EnCircularqueue
    enCircularqueue(&q, 12);
    enCircularqueue(&q, 20);
    enCircularqueue(&q, 40);
    enCircularqueue(&q, 100);

    // DCircularqueue
    printf("DeQueuing element %d \n", deCircularqueue(&q));
    printf("DeQueuing element %d \n", deCircularqueue(&q));
    printf("DeQueuing element %d \n", deCircularqueue(&q));
    printf("DeQueuing element %d \n", deCircularqueue(&q));

    enCircularqueue(&q, 77);
    enCircularqueue(&q, 88);
    enCircularqueue(&q, 99);
    enCircularqueue(&q, 66);

    // Checks
    if (isEmpty(&q))
    {
        printf("Circularqueue is empty");
    }
    if (isFull(&q))
    {
        printf("Circularqueue is full");
    }

    return 0;
}