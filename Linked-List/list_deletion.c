#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};


//TRAVERSING THE LINKED LIST
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}


// Case 1: Deleting the first element from the linked list
struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}


// CASE-2.DELETING THE ELEMENT  AT A GIVEN INDEX FROM YHE LINKED  LIST
struct Node *deleteatindex(struct Node * head,int index){
    struct Node *p=head;
    struct Node *q=head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

//CASE-3.DELETING THE LAST ELEMENT
struct Node * deleteAtLast(struct Node * head){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
    return head;
}



int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    // head = deleteFirst(head); // For deleting first element of the linked list
    // head = deleteAtIndex(head, 2);
    head = deleteAtLast(head);
    printf("Linked list after deletion\n");
    linkedListTraversal(head);

    return 0;
}


//Time to ask some question
/*question- how free ptr will delete the node it is simply going to delete the pointer ptr and the adress inside it i guess

answere-It deallocates the memory that was used by the node ptr is pointing to.
Important: free(ptr) does not "delete the pointer ptr"; it deallocates the memory that ptr points to. The pointer ptr itself is a local variable 
and still exists after the free call, but the memory it was pointing to (i.e., the first node of the list) is now freed and no longer accessible.




question- do the orginal head element exist?

answere-No, the original head node does not exist after you perform the deletion operation. Let's clarify this step by step.

Understanding What Happens to the Original Head Node:
Initial Setup:

You have a linked list with nodes, and head is pointing to the first node.

Example:
code
head -> [10 | *] -> [20 | *] -> [30 | NULL]
Storing the Head Node:

struct Node * ptr = head; creates a pointer ptr that points to the same node as head. So, both ptr and head initially point to the first node:

code
ptr  -> [10 | *]
head -> [10 | *]
Moving the Head Pointer:

head = head->next; moves the head pointer to the second node:

code
ptr  -> [10 | *]
head -> [20 | *] -> [30 | NULL]
Now, head points to the second node, and ptr still points to the original first node.
Freeing the Original Head Node:

free(ptr); deallocates the memory occupied by the node that ptr points to (which is the original head node):

code
head -> [20 | *] -> [30 | NULL]
After this step, the memory that the original head node occupied is released, and that node no longer exists in memory.


Key Points:
Original Head Node: The original head node (e.g., [10 | *]) is completely removed from memory after free(ptr). It no longer exists or holds any 
data. New Head Node: After deletion, head points to the second node in the original list, which is now the first node of the updated list.
Final State of the List:
After the deleteFirst function executes, the linked list looks like this:

code
head -> [20 | *] -> [30 | NULL]
The original head node [10 | *] has been deleted, and its memory has been freed, so it no longer exists.

*/