#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

STACK *create_stack(unsigned int capacity)
{
    STACK *newstack=(STACK *)malloc(sizeof(STACK));
    newstack->top=-1;
    newstack->capacity=capacity;
    newstack->array=(int *)malloc(capacity*sizeof(int));

    if(newstack->array==NULL){
        printf("Failed to create the stack");
        return NULL;
    }
    
    return newstack;

}

STACK *push(STACK *s,int d)
{
    s->top+=1;
    if(s->top==s->capacity){
          s->capacity=2*s->capacity;
          s->array=(int *)realloc(s->array,s->capacity);
          s->array[s->top]=d;
    }
    else{
        s->array[s->top]=d;
    }

    return s;
}

int pop(STACK *s){
    if(s->top==-1){
        printf("Stack Underflow");
        return -1;
    }
    else{
        int data=s->array[s->top];
        s->top-=1;
        return data;
    }
}

void Display(STACK *s)
{
     if(s->capacity==0)
        printf("Stack is empty");
     else{
        for(int i=0;i<=s->top;i++)
            printf("%d->",s->array[i]);
     }   
    
}

