//PREORDER TRAVERSAL
#include<stdio.h>
#include<malloc.h>
 
struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n;//well here we jsut created a node pointer
    n=(struct nod*)malloc(sizeof(struct node));//now we did here is very simple that is we are allocating memeory to th node hence crating the node
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;

}

void preorder(struct node*root){
    if(root!=NULL){
        print("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    //So lets crate the nodes for the ltree
    struct node*p=createnode(4);
    struct node*p1=createnode(4);
    struct node*p2=createnode(4);
    struct node*p3=createnode(4);
    struct node*p4=createnode(4);


    //we should link the nodes with their childrens in order to do operations
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    preorder(p);
    return 0;
}