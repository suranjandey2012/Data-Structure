#include "Queue.h"

int main()
{
    DATA d;
    QUEUE *q=create_Queue(3);
    d=87;
    enqueue(q,&d);
    d=16;
    enqueue(q,&d);
    d=36;
    enqueue(q,&d);
    dequeue(q,&d);
    dequeue(q,&d);
    dequeue(q,&d);
    dequeue(q,&d);
    d=69;
    enqueue(q,&d);
    d=30;
    enqueue(q,&d);
    d=68;
    enqueue(q,&d);
    d=57;
    enqueue(q,&d);
    d=65;
    enqueue(q,&d);
    dequeue(q,&d);
    d=65;
    enqueue(q,&d);
    d=100;
    enqueue(q,&d);
    dequeue(q,&d);
    printf("Removed item is:%d\n",d);
    d=100;
    enqueue(q,&d);
    deletequeue(q);
    return 0;
}