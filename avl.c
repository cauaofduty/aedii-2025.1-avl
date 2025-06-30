#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

node* createNode(int value){

    node* newNode = (node*)malloc(sizeof(node));
    
    if(!newNode){
        printf("Erro ao alocar nó\n");
        return NULL;
    }

    newNode->value = value;
    newNode->cb = 0;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int height(node *root){
    if(!root) return -1;

    int leftHeight = height(root->left) + 1;
    int rightHeight = height(root->right) + 1;
    
    if (leftHeight > rightHeight) return leftHeight;

    else return rightHeight;
}

void cbUpdate(node* root){
    if(root) root->cb = height(root->right) - height(root->left);
}


node* rotateRight(node* root){
    
    node *pivot = root, *t1 = pivot->left, *t2 = t1->right; 
    
    t1->right = pivot;
    pivot->left = t2;

    cbUpdate(pivot);
    cbUpdate(t1);
    cbUpdate(t2);

    return t1;
}

node* rotateLeft(node* root){
    
    node *pivot = root, *t1 = pivot->right, *t2 = t1->left; 
    
    t1->left = pivot;
    pivot->right = t2;

    cbUpdate(pivot);
    cbUpdate(t1);
    cbUpdate(t2);

    return t1;
}

node *rotateDoubleLeft(node *root){}

node *rotateDoubleRight(node *root){}


node* balance(node* root){

    //rotação à direta
    if(root->cb > 1 && root->right->cb >= 0) root = rotateLeft(root);

    return root;

}

node* insert(node *root, int value){
    if(!root) return createNode(value); 
    
    //direciona descida
    if(value >= root->value) root->right = insert(root->right, value);
     
    else root->left = insert(root->left, value);

    //atualiza cb e checa balanceamento
    cbUpdate(root);
    
    return balance(root);

}


void inOrder(node *root){

    if(!root) return;

    printf("[%d cb: %d]", root->value, root->cb);

    inOrder(root->left);

    inOrder(root->right);
    
}