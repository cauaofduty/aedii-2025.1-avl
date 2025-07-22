#ifndef AVL_H
#define AVL_H

typedef struct Node{
    int value;
    int cb;
    struct Node* left;
    struct Node* right;
}node;


node* insert(node* root, int value, int* raised);
void preOrder(node* root);
node* rightRotate(node* root);
node* doubleRightRotation(node* root);
node* rightRotationCheck(node *root);
node* leftRotate(node* root);
node* doubleLeftRotation(node* root);
node* leftRotationCheck(node *root);
node *removeNode(node* root, int value, int *changed);
int greatestPredecessor(node* root);
#endif // MAIN_H
