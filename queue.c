#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue *create_queue(int len)
{
    Queue *new_queue = (Queue*)malloc(sizeof(Queue));
    new_queue ->length = len;
    new_queue ->count = 0;
    new_queue ->front = 0;
    new_queue ->rear = 0;
    new_queue ->buffer = (int*)malloc(sizeof(int) * len);
    printf("Queue created!\n");
    return new_queue;
}
void enqeue(Queue *q, int d)
{
    q ->count += 1;
    if(q->count >= q->length)
    {
        printf("QUEUE Overflow!!");
        exit(EXIT_FAILURE);
    }
    else
    {
        q ->buffer[q->rear] = d;
        q ->rear = (q->rear+1) % (q->length);
    }
}
int dequeue(Queue *q)
{
    q->count = q->count - 1;
    if(q->count <0)
    {
        printf("QUEUE Underflow!");
        exit(EXIT_FAILURE);
    }
    int r = q->buffer[q->front];
    q->front = (q->front +1) % (q->length);
    return r;
}
void display(Queue *q)
{
    for(int i = 0; i< q->count;i++)
    {
        int index = (q->front % q ->length;
        printf("%d", q->buffer[q->front]);
    }
}