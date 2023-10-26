#include "Stack2.h"
#include<string.h>

STACK *createstack(unsigned int capacity){
    STACK *s;
    if(NULL==(s=(STACK *)malloc(sizeof(STACK))))
    {
        fprintf(stderr,"Memory Allocation Failur for Stack\n");
        exit(1);
    }

    if(NULL==(s->elements=(DATA *)malloc(capacity*sizeof(DATA))))
         {
            fprintf(stderr,"Memory allocation failure for the Array");
            exit(1);
         }
    s->capacity=capacity;
    s->top=-1;
    return s;
}

int push(STACK *s,DATA *d)
{
    if(s->capacity==s->top+1)
    {
        s->capacity=s->capacity*2;
        if(NULL==(s->elements=(DATA *)realloc(s->elements,sizeof(DATA)*s->capacity)))
        {
            fprintf(stderr,"Failed increase the stack size\n");
            return -1;
        }
        s->top=s->top+1;
        printf("Pushing %s\n",*d);
        strcpy(s->elements[s->top],*d);
        printf("The stack top is %d ---->%s\n",s->top,s->elements[s->top]);
        return 1;
    }

    s->top=s->top+1;
    printf("Pushing %s\n",*d);
    strcpy(s->elements[s->top],*d);
    printf("The stack top is %d ---->%s\n",s->top,s->elements[s->top]);
    return 1;
}


int pop(STACK *s,DATA *d)
{
    if(-1==s->top)
    {
        printf("Stack underflow\n");
        return -1;
    }
    strcpy(*d,s->elements[s->top]);
    printf("Popping %s\n",*d);
    s->top=s->top-1;
    if(-1!=s->top)
         printf("The stack top is %d ---->%s\n",s->top,s->elements[s->top]);
    else
        printf("The stack top is %d\nStack is empty\n",s->top);

    return 1;
}


int freestack(STACK *s)
{
    for(int i=0;i<s->capacity;i++)
       free(s->elements[i]);
    free(s); 
    return 0;  
}

