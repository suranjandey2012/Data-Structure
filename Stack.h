#ifndef S_H
#define S_H
#include<stdio.h>

typedef int DATA;

typedef struct {

    int capacity,top;
    DATA *array;
} STACK;

extern STACK *create_stack(unsigned int capacity);
extern int push(STACK *s,DATA *d);
extern int pop(STACK *s,DATA *d);
extern int clearstack(STACK *s);
//extern void Display(STACK *s);

#endif