#ifndef SH
#define SH
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 256

typedef char DATA[MAXSIZE];

typedef struct {
  int capacity,top;
  DATA *elements;
}STACK;

extern STACK *createstack(unsigned int capacity);
extern int push(STACK *s,DATA *d);
extern int pop(STACK *s,DATA *d);
extern int freestack(STACK *s);

#endif