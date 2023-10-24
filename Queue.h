#ifndef Q_H
#define Q_H
#include<stdio.h>
#include<stdlib.h>

typedef int DATA;
typedef struct{
    int capacity,num_elements,front,rear;
    DATA *elements;
} QUEUE;

extern QUEUE *create_Queue(DATA capacity);
extern int enqueue(QUEUE *q,DATA *d);
extern int dequeue(QUEUE *q,DATA *d);
extern int deletequeue(QUEUE *q);
#endif