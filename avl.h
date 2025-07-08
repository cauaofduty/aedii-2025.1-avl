#ifndef AVL_H
#define AVL_H

typedef struct Node{
    int value;
    int cb;
    struct Node* left;
    struct Node* right;
}node;

// Function declarations
node* insert(node* root, int value, int* raised);
void posOrder(node* root);
node* rotateRight(node* root);
node* rotateDoubleRight(node* root);
node* rotateLeft(node* root);
node* rotateDoubleLeft(node* root);
node *removeNode(node* root, int value, int *changed);
int greatestPredecessor(node* root);
#endif // MAIN_H