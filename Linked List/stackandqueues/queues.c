#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef int Element;

typedef struct _queue
{
    Element* storage;
    int front, rear, count, capacity;
}*QUEUE_ARR;

QUEUE_ARR createQ(int capacity)
{
    QUEUE_ARR q = (QUEUE_ARR)malloc(sizeof(struct _queue));
    q->storage = (Element*)malloc(sizeof(Element)*capacity);
    q->front = q->rear = q->count = 0;
    q->capacity = capacity;
    return q;
}

int isEmpty(QUEUE_ARR q){
    return q->count == 0;
}

int isFull(QUEUE_ARR q){
    return q->count == q->capacity;
}

void enqueue(QUEUE_ARR q, Element data){
    if(!isFull(q)){
    q->storage[q->rear] = data;
    q->rear = (q->rear + 1) % q->capacity;
    q->count++;
    }
}

Element dequeue(QUEUE_ARR q){
    if(!isEmpty(q)){
    Element x = q->storage[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->count--;
    return x;
    } else
    return -1; 
}

int main() {
    int m = 6,n = 4;
    QUEUE_ARR q = createQ(n);
    int limit = n +1;
    for(int i = 1; i < limit; i++)
        enqueue(q,i);
    while(q->count > 1)
    {
        for(int i = 1; i < m; i++)
            enqueue(q, dequeue(q));
        dequeue(q);
    }
    printf("Winner: %d",dequeue(q));
    return 0;
}