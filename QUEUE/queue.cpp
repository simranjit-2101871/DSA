/*Data:

In order to create a queue, we need two pointers, one pointing to the insertion end, to gain knowledge about the address where the new element 
will be inserted to. And the other pointer pointing to the deletion end, which holds the address of the element which will be deleted first. Along 
with that, we need the storage to hold the element itself.

Methods:

Here are some of the basic methods we would want to have in queues:

1. enqueue() : to insert an element in a queue.

2. dequeue(): to remove an element from the queue

3. firstVal(): to return the value which is at the first position.

4. lastVal(): to return the value which is at the last position.

5. peek(position):  to return the element at some specific position.

6. isempty() / isfull(): to determine whether the queue is empty or full, which

A queue is a collection of elements with certain operations following FIFO (First in First Out) discipline. We insert at one end and delete from 
the other. And this is what you have to keep in mind for now. */

#include<iostream>
//#include <cstdlib>
using namespace std;
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        cout<<"The queue is full"<<endl;
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        cout<<"Element enqued="<<val<<endl;
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        cout<<" the queue is empty"<<endl;
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
 
int main(){
    struct queue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q)); 
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);
 
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
 
    return 0;
}
