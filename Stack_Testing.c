#include "Stack.h"
#include "Stack.h"
int main()
{
    STACK *s=create_stack(3);
    s=push(s,1);
    Display(s);
    printf("\n");
    s=push(s,2);
    Display(s);
    printf("\n");
    s=push(s,3);
    Display(s);
    printf("\n");
    s=push(s,4);
    Display(s);
    printf("\n");
    s=push(s,5);
    Display(s);
    printf("\n");
    int data=pop(s);
    printf("\nPopped:%d\n",data);
    Display(s);
    data=pop(s);
    printf("\nPopped:%d\n",data);
    Display(s);
    data=pop(s);
    printf("\nPopped:%d\n",data);
    Display(s);
    data=pop(s);
    printf("\nPopped:%d\n",data);
    Display(s);
    data=pop(s);
    printf("\nPopped:%d\n",data);
    Display(s);
    data=pop(s);
    printf("\nPopped:%d\n",data);
    Display(s);
    data=pop(s);
    printf("\nPopped:%d\n",data);
    Display(s);
    data=pop(s);
    printf("\nPopped:%d\n",data);
    Display(s);
    push(s,2);
    Display(s);
    printf("\n");
    return 0;
}

