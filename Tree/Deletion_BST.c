#include <stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return 0;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

struct node *inorderpredecess(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deletenode(struct node *root, int value)
{
    struct node *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    // This is the condition for leaf node which is very simple to understand
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // Condition where the node is not a leaf node
    if (value < root->data)
    {
        root->left = deletenode(root->left, value);
    }

    else if (value > root->data)
    {
        deletenode(root->right, value);
    }
    else
    {
        ipre = inorderpredecessor(root);
        root->data = ipre->data;
        deletenode(root->left, ipre->data);
    }
}

int main()
{
    struct node *p = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);

    // linking the node part
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inorder(p);
    printf("\n");
    deletnode(p, 3);
    inorder(p);
    return 0;
}
