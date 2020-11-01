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
void enqueue(Queue *q, int d)
{
    q ->count += 1;
    if(q->count > q->length)
    {
        printf("QUEUE Overflow!!");
        exit(EXIT_FAILURE);
    }
    else
    {
        q ->buffer[q->rear] = d;
        printf("buufer[%d] is %d",q->rear, q->buffer[q->rear]);
        q ->rear = (q->rear+1) % (q->length);
        printf("rear is %d",q->rear);
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
    int index = q->front;
    for(int i = 0; i<(q->count);i++)
    {
        index = index % (q ->length);
        printf("%d", q->buffer[index]);
        printf(" ");
        index = index + 1;
        
    }
    printf("\n");
}
void delete_queue(Queue *q)
{
    free(q);
    printf("Queue deleted!");
}