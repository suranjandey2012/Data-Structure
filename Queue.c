#include "Queue.h"

QUEUE *create_Queue(DATA capacity)
{
    QUEUE *q;
    
    if(NULL==(q=(QUEUE *)malloc(sizeof(QUEUE)))){
        fprintf(stderr,"Failed to allocate memeory for queue\n");
        exit(1);
    }

    q->capacity=capacity;
    q->front=q->rear=-1;
    if(NULL==(q->elements=(DATA *)malloc(capacity*sizeof(DATA))))
    {
        fprintf(stderr,"Memeory allocation failure for queue elements\n");
        exit(1);
    }

    return q;   
}

int enqueue(QUEUE *q,DATA *d){
    if(q->rear==-1){
        if(q->capacity==0){
            printf("Queue has zero capacity\n");
            return -1;
        }
        else{
            q->rear=q->front=0;
            printf("Enqueue %d\n",*d);
            q->elements[q->rear]=*d;
            printf("Queue Head= %d ----> %d\n",q->front+1,q->elements[q->front]);
        }

        return 1;
    }
    else if((q->rear+1)%(q->capacity)==q->front){
        printf("Queue is full\n");
        return -1;
    }
    else{
        q->rear=(q->rear+1)%q->capacity;
        printf("Enqueue %d\n",*d);
        q->elements[q->rear]=*d;
        printf("Queue Head= %d ---> %d\n",q->front+1,q->elements[q->front]);
        return 1;
    }
}


int dequeue(QUEUE *q,DATA *d){
     if(-1==q->front)
     {
        printf("Queue is empty\n");
        return -1;
     }
     else if(q->rear==q->front)
     {
        *d=q->elements[q->front];
        q->front=q->rear=-1;
        printf("Dequeue %d\n",*d);
        printf("Queue Head=%d\n",q->front+1);
        printf("Queue is empty now\n");
        return 1;
     }
     else{
        *d=q->elements[q->front];
        q->front=(q->front+1)%q->capacity;
        printf("Dequeue %d\n",*d);
        printf("Queue Head=%d --> %d\n",q->front+1,q->elements[q->front]);
        return 1;
     }
}


int deletequeue(QUEUE *q){
    free(q->elements);
    free(q);
    return 0;
}
