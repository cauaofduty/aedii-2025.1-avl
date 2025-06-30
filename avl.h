#ifndef AVL_H
#define AVL_H

typedef struct Node{
    int value;
    int cb;
    struct Node* left;
    struct Node* right;
}node;

// Function declarations
node* insert(node*root, int value);
void inOrder(node *root);
node* rotateRight(node*root);
node* rotateDoubleRight(node*root);
node* rotateLeft(node*root);
node* rotateDoubleLeft(node*root);
int height(node*root);
node *removeNode(node*root, int value);
#endif // MAIN_H