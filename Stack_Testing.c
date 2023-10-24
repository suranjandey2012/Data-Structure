#include "Stack.h"
int  main()
{
    STACK *s=create_stack(3);
    DATA d;
    d=87;
    push(s,&d);
    d=16;
    push(s,&d);
    d=36;
    push(s,&d);
    pop(s,&d);
    pop(s,&d);
    d=22;
    push(s,&d);
    pop(s,&d);
    d=91;
    push(s,&d);
    d=64;
    push(s,&d);
    pop(s,&d);
    pop(s,&d);
    pop(s,&d);
    d=69;
    push(s,&d);
    d=30;
    push(s,&d);
    d=90;
    push(s,&d);
    d=92;
    push(s,&d);
    clearstack(s);
    return 0; 
}

