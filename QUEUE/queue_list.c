#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;



//traverse karo queue ko
void traversal(struct node*ptr){
    printf("Will print the elements of this queue");
    while(ptr!=NULL){
        printf("Element :%d\n",ptr->data);
    }

}



//insert karo element ko
void en(int val){
    struct node *n = (struct node *) malloc(sizeof(struct node));
    if(n==NULL){
        printf("QUEUE is full");
    }
    else{
        n->data = val;
        n->next = NULL;
    }
    //if there is no node then
    if(f==NULL){
        f=r=n;
    }
    else{
        r->next=n;
        r=n;
    }

}



//delete karo element ko
int de(){
    int val=-1;
    struct node* ptr=f;
    if(f==NULL){
        printf("Queue is empty\n");
    }
    else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}



int main(){
    
    printf("Dequeing the element %d\n",de());

    en(34);
    en(4);
    en(7);
    en(17);

    printf("Dequeuing element %d\n", de());
    printf("Dequeuing element %d\n", de());
    printf("Dequeuing element %d\n", de());
    printf("Dequeuing element %d\n", de());

    traversal(f);
    return 0;
}