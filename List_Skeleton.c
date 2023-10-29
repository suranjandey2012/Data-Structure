#include "common.h"

#define MAX_VALUE 1000

typedef int DATA;
typedef struct node {
    DATA data;
    struct node *next, *prev;
} NODE;
typedef struct {
    unsigned int length;
    NODE *head, *tail;
} LIST;

NODE *create_node(DATA d);
void init_list(LIST *l);
int insert(LIST *l, unsigned int index, DATA d);  //Return -1 on insertion failure
int delete(LIST *l, unsigned int index, DATA *d);  //For delete store the deleted data in the variable d.
int find_index(LIST *l, DATA d);
int find_value(LIST *l, unsigned int index, DATA *d);
void print_list(LIST *l);
void free_list(LIST *l);


NODE *create_node(int d) {
    NODE *nptr;
    if (NULL == (nptr = Malloc(1, NODE)))
        ERR_MESG("out of memory");
    nptr->data = d;
    nptr->next =nptr->prev =  NULL;
    return nptr;
}

void init_list(LIST *l) {
    if(NULL==(l=(LIST *)malloc(sizeof(LIST))))
         fprintf(stderr,"Unable to create the list");
    l->length = 0;
    l->head = l->tail = NULL;
    return;
}
    

int insert(LIST *l, unsigned int index, DATA d) {
    
    if(index>l->length || index<0)
    {
        fprintf(stderr,"Index %d is out of bounds: Trying to insert out side range\n",index);
        return -1;
    }
    else if(0==index)
    {
        if(0==l->length)  // First Node insertion
        {
            NODE *newnode=create_node(d);
            printf("Inserting %d at index %d\n",d,index);
            l->head=l->tail=newnode;
            l->length=l->length+1;
        }else{
             NODE *newnode=create_node(d);
             printf("Inserting %d at index %d\n",d,index);
             newnode->next=l->head;
             l->head=newnode;
             l->length=l->length+1;
        }
    }
    else if(index==l->length){   //Tail insertion
        NODE *newnode=create_node(d);
        printf("Inserting %d at index %d\n",d,index);
        l->tail->next=newnode;
        newnode->prev=l->tail;
        l->tail=newnode;
        l->length=l->length+1;
    }else{
        NODE *newnode=create_node(d);
        NODE *temp=l->head;
        printf("Inserting %d at index %d\n",d,index);
        for(int i=0;i<index;i++)
            temp=temp->next;
        newnode->next=temp;
        newnode->prev=temp->prev;
        temp->prev->next=newnode;
        temp->prev=newnode;
        l->length=l->length+1;    
    }
    return 1;
}

int delete(LIST *l, unsigned int index, DATA *d) {
    if(index<0 || index>=l->length){
      fprintf(stderr,"INDEX IS OUT OF BOUNDS\n");
      return -1;
    }
    else if(0==index)
    {
        if(1==l->length) // Deleting the last remaining or the only node in the list
        {
            NODE *temp;
            temp=l->head;
            *d=temp->data;
            printf("Deleting %d at index %d\n",temp->data,index);
            l->head=l->tail=NULL;
            l->length=l->length-1;
            free(temp);
        }else{               //If there are more than 1 node in the list
            NODE *temp;
            temp=l->head;
            *d=temp->data;
            printf("Deleting %d at index %d\n",temp->data,index);
            l->head=l->head->next;
            l->head->prev=NULL;
            l->length=l->length-1;
            free(temp);
        }
    }else if(l->length-1==index) //If the node to be deleted is the last node
    {
        NODE *temp;
        temp=l->tail;
        *d=temp->data;
        printf("Deleting %d at index %d\n",temp->data,index);
        l->tail=l->tail->prev;
        l->length=l->length-1;
        free(temp);
    }else{
        NODE *temp=l->head;
        for(int i=0;i<index;i++)
             temp=temp->next;
        *d=temp->data;
        printf("Deleting %d at index %d\n",temp->data,index);
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        l->length=l->length-1;     
    }
    return 1;
}

int find_index(LIST *l, DATA d) {
    if(0==l->length)
    {
        fprintf(stderr,"List is empty\n");
        return -1;
    }
    NODE *temp=l->head;
    for(int i=0;i<l->length;i++){
        if(d==temp->data)
            return i;
        temp=temp->next;    
    }
    fprintf(stderr,"DATA does not exists in the list\n");
    return -1;
}

int find_index_in_sorted(LIST *l, DATA d) {
    if(0==l->length){
        return 0;
    }
    NODE *temp=l->head;
    int i=-1;
    temp=l->head;
    while(NULL!=temp) // Check for the index in a sorted sequence using the partition method
    { 
        if(temp->data<d)
            i++;
        temp=temp->next;    
    }
    return (i+1);
}

int find_value(LIST *l, unsigned int index, DATA *d) {
    if(0==l->length){
        fprintf(stderr,"List is empty now\n");
        return -1;
    }
    else if(index<0||index>=l->length){
        fprintf(stderr,"INDEX IS OUT OF BOUNDS\n");
        return -1;
    }else{
        NODE *temp=l->head;
        for(int i=0;i<index;i++)
               temp=temp->next;
        *d=temp->data;       
    }    
    return 1;
}

void print_list(LIST *l) {
    if(0==l->length)
         fprintf(stderr,"List is empty\n");
    else{
        NODE *temp=l->head;
        for(int i=0;i<l->length;i++){
            printf("|%d|-->",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }     
    return;
}

void free_list(LIST *l) {
    if(l->length==0)
        free(l);
    else{
        NODE *temp;
        NODE *next;
        temp=next=l->head;
        for(int i=0;i<l->length;i++)
        {
            temp=next;
            next=next->next;
            free(temp);
        }
        free(l);
    }    
    return;
}


int main(int ac, char *av[])
{
    int n, index, i;
    DATA d, d1;
    NODE *nptr;
    LIST l;

    if (ac < 2)
        ERR_MESG("Usage: linked-list <number>");
    n = atoi(av[1]);
    srand((int) time(NULL));

    init_list(&l);
    for (i = 0; i < n; i++) {
        d = rand() % MAX_VALUE;
        index = find_index_in_sorted(&l, d);
        if (-1 == insert(&l, index, d))
            fprintf(stderr, "Inserting %d at index %d failed\n", d, index);
        else
            fprintf(stderr, "Inserted %d at index %d successfully\n", d, index);
        print_list(&l);
    }

    while (l.length > 0) {
        index = rand() % l.length;
        if (-1 == find_value(&l, index, &d))
            fprintf(stderr, "Failed to find value at index %d\n", index);
        else {
            fprintf(stderr, "Found %d at index %d, deleting\n", d, index);
            if (-1 == delete(&l, index, &d1))
                fprintf(stderr, "Delete failed\n");
            else
                assert(d == d1);
            print_list(&l);
        }
    }

    free_list(&l);
    return 0;
}