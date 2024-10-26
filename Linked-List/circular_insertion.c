/*
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("The element is :%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// insert at the first
struct node *insert_at_first(struct node *head, int data)
{
    struct node *p = head;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    p = p->next;
    ptr->data = data;
    while (p->next != head)
    {
        p = p->next;
    }
    ptr->next = head;
    p->next = ptr;
    head = ptr;
    return head;
}

// insert ing the node at a particular index
struct node *insert_at_index(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = p->next;
    return head;
}

// insert at the end of the list it will determined by p->next=head
struct node *inser_at_end(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head->next;
    ptr->data = data;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;

    // Allocating the memory the nodes
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    // ab krenge linking
    head->data = 4;
    head->next = second;

    second->data = 5;
    second->next = third;

    third->data = 6;
    third->next = head;

    // traverse kar list nu
    traversal(head);
    head = insert_at_first(head, 10);
    traversal(head);
    printf("\n\n");

    head = insert_at_index(head, 56, 1);
    traversal(head);
    printf("\n\n");

    head = inser_at_end(head, 78);
    traversal(head);
    printf("\n\n");

    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *head)
{
    if (head == NULL)
        return;

    struct node *ptr = head;
    do
    {
        printf("The element is: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}




// Insert at the beginning of the circular linked list
struct node *insert_at_first(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    if (head == NULL)
    { // If the list is empty
        ptr->next = ptr;
        return ptr;
    }

    struct node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }

    ptr->next = head;
    p->next = ptr;
    return ptr; // New head
}




// Insert at a particular index
struct node *insert_at_index(struct node *head, int data, int index)
{
    if (index == 0)
    {
        return insert_at_first(head, data);
    }

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;

    while (i < index - 1)
    {
        p = p->next;
        if (p == head)
        { // Index is out of bounds
            printf("Index out of bounds\n");
            free(ptr);
            return head;
        }
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}




// Insert at the end of the circular linked list
struct node *insert_at_end(struct node *head, int data)
{
    if (head == NULL)
    {
        return insert_at_first(head, data);
    }

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;

    while (p->next != head)
    {
        p = p->next;
    }

    ptr->next = head;
    p->next = ptr;
    return head;
}


// insert after a specific node
struct node *insert_after_node(struct node *head, struct node *prevNode, int data)
{
    if (head == NULL)
    {
        return insert_at_first(head, data);
    }
    struct node *ptr =(struct node *)malloc(sizeof(struct node)) ;
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
}

int main()
{
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    // Allocating memory for nodes
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    // Linking nodes
    head->data = 4;
    head->next = second;

    second->data = 5;
    second->next = third;

    third->data = 6;
    third->next = head;

    // Traverse the list
    traversal(head);
    head = insert_at_first(head, 10);
    traversal(head);
    printf("\n\n");

    head = insert_at_index(head, 56, 1);
    traversal(head);
    printf("\n\n");

    head = insert_at_end(head, 78);
    traversal(head);
    printf("\n\n");

    head = insert_after_node(head, third, 45);
    traversal(head);
    printf("\n\n");

    return 0;
}
