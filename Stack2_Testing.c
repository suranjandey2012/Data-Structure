#include "Stack2.h"

int main(int argc,char **argv)
{
    STACK *s;
    DATA inbuff;
    FILE *fp=fopen(argv[1],"r");
    s=createstack(1);
    while(NULL!=fgets(inbuff,sizeof(DATA),fp))
             push(s,strdup(inbuff));
    pop(s,&inbuff);
    pop(s,&inbuff);
    pop(s,&inbuff);
    pop(s,&inbuff);
    pop(s,&inbuff);
    freestack(s);
    fclose(fp);
    return 0;
}