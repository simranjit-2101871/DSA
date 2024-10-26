#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedlisttraversal(struct Node *ptr){

    while(ptr!=NULL){
        printf("Elements are :%d\n",ptr->data);
        ptr=ptr->next;
    }

}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //Dynamicaly allocation of memeory in heap
    head= (struct Node *)malloc(sizeof(struct Node));
    second= (struct Node *)malloc(sizeof(struct Node));
    third= (struct Node *)malloc(sizeof(struct Node));
    fourth= (struct Node *)malloc(sizeof(struct Node));

    //Link first and second nodes

    head->data=7;
    head->next=second;

    //Link the second node with third
    second->data=11;
    second->next=third;

    //Link the third nose with null means linked list is finished
    third->data=20;
    third->next=NULL;

    linkedlisttraversal(head);
}


//Time for sime wuestions
/*Yes, within a structure, the fields (data and next in your case) are stored contiguously in memory, but their memory addresses are 
relative to the structure's base address. Let's break this down:

Structure Memory Layout:
Structure Base Address:

The base address of the structure (e.g., head or ptr) refers to the start of the structure in memory.
Fields Within the Structure:

The fields of the structure (like data and next) are stored at specific offsets from the base address.*/



/* if you modify head->next or second->next, the changes will automatically be reflected in the main function.

Here's why:
Pointers and Memory: The head and second pointers (or any other node pointers like head->next, second->next, etc.) in a linked list are 
pointing to nodes in memory. When you modify head->next or second->next, you're directly changing the next pointer of the node that head
 or second is pointing to.

Direct Modification: Since these modifications are being made directly to the memory where the nodes are stored, the changes are 
immediately visible throughout the program. The pointer in the main function (whether it's head, second, etc.) still points to the same 
node, but now that node's next pointer has been updated.*/