#include<iostream>
#include<stdlib.h>
using namespace std;

struct circularQueue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct circularQueue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct circularQueue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}
 
void enqueue(struct circularQueue *q, int val){
    if(isFull(q)){
        cout<<"The queue is full"<<endl;
    }
    else{
        q->r = (q->r +1)%q->size;
        q->arr[q->r] = val; 
        cout<<"The enqueued element:"<<val<<endl;
    }
}
 
int dequeue(struct circularQueue *q){
    int a = -1;
    if(isEmpty(q)){
        cout<<"The queue is empty"<<endl;
    }
    else{
        q->f = (q->f +1)%q->size;
        a = q->arr[q->f]; 
    }
    return a;
}
 
 
int main(){
    struct circularQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    cout<<"Dqueuing element:"<< dequeue(&q)<<endl;
    cout<<"Dequeuing element:"<< dequeue(&q)<<endl;
    cout<<"Dequeuing element:"<< dequeue(&q)<<endl; 
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);
 
    if(isEmpty(&q)){
        cout<<"The queue is empty"<<endl;
    }
    if(isFull(&q)){
        cout<<"The queue is full"<<endl;
    }
 
    return 0;
}
//double ended queue yet to be done