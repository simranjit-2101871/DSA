#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void linkedlisttraversal(struct node *ptr) {
    while(ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}


//INSERTION AT THE BEGINNNG OF THE LIST
struct node *insertatfirst(struct node *head,int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}



//INSERTION AT THE INDEX
struct node * insertAtIndex(struct node *head, int data, int index){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    struct node * p = head;
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}




//INSERTION OF NODE AT THE END
struct node * insertAtEnd(struct node *head, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
    struct node * p = head;
 
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}







int main() {
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    // Allocate memory for nodes in the linked list in heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 20;
    third->next = fourth;

    // Link fourth node to NULL to signify end of list
    fourth->data = 65;
    fourth->next = NULL;

    printf("Linked list before insertion\n");
    linkedlisttraversal(head);


     head = insertatfirst(head, 56);//list-insertion.c:99:11: warning: assignment makes pointer from integer without a cast [-Wint-conversion]//can also get this error if the fucntion siganture does not match
      head = insertatFirst(head, 56);
     head = insertAtIndex(head, 56, 1);
     head = insertAtEnd(head, 56);
    //head = insertAfterNode(head, third, 45);
    printf("\nLinked list after insertion\n");
    linkedlisttraversal(head);
    return 0;
    
}



//some questions need to be answered
/*in arguments pointer is being used so changes made  in the function should auotmaticaly reflect in the main fucntion

answere-

Pointer Dereferencing:
When you modify the contents of the memory location that a pointer points to (e.g., changing the next pointer of a node), those changes are 
reflected in the calling function.

Pointer Reassignment:
If you modify the pointer itself (e.g., by making it point to a different memory location), that change is not reflected in the calling function unless you explicitly return the modified pointer.*/