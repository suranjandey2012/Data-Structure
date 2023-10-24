#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

STACK *create_stack(unsigned int capacity)
{
    STACK *newstack=(STACK *)malloc(sizeof(STACK));
    newstack->top=-1;
    newstack->capacity=capacity;
    if(NULL==(newstack->array=(int *)malloc(capacity*sizeof(int)))){
         fprintf(stderr,"Failed to create stack");
         exit(1);
    }

    /*if(newstack->array==NULL){
        printf("Failed to create the stack");
        return NULL;
    }*/
    
    return newstack;

}

int push(STACK *s,DATA *d)
{
    printf("Pushing %d\n",*d);
    s->top+=1;
    if(s->top==s->capacity){
          s->capacity=2*s->capacity;
          if(NULL==(s->array=(int *)realloc(s->array,s->capacity))){
                   fprintf(stderr,"Failed to increase size");
                   return -1;
          }
          s->array[s->top]=*d;
    }
    else{
        s->array[s->top]=*d;
    }

    printf("Stack top=%d-->%d\n",s->top+1,s->array[s->top]);

    return 1;
}

int pop(STACK *s,DATA *d){
    if(s->top==-1){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        *d=s->array[s->top];
        s->top-=1;
        printf("Popped %d\n",*d);
        if(s->top==-1)
          printf("Stack empty\n");
        else
           printf("Stack top=%d-->%d\n",s->top+1,s->array[s->top]);
        return 1;
    }
}

int clearstack(STACK *s)
{
    free(s->array);
    free(s);
    return 0;
}


/*void Display(STACK *s)
{
     if(s->capacity==0)
        printf("Stack is empty");
     else{
        for(int i=0;i<=s->top;i++)
            printf("%d->",s->array[i]);
     }   
    
}*/

