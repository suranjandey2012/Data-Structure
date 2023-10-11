#ifndef S_H
#define S_H
#include<stdio.h>
typedef struct {

    int capacity,top;
    int *array;
} STACK;

extern STACK *create_stack(unsigned int capacity);
extern STACK *push(STACK *s,int d);
extern int pop(STACK *s);
extern void Display(STACK *s);
#endif