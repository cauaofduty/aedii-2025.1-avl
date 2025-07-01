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

//rever
node* rotateRight(node* root){

    node *a = root, *b = a->left, *c = b->right;
    
    b->right = a;
    b->cb = 0;


    a->left = c;
    a->cb = 0;

    return b;
}
//rever
node* rotateLeft(node* root){
    
    node *a = root, *b = a->right, *c = b->left;

    b->left = a;
    b->cb = 0;

    a->right = c;
    a->cb = 0;

    return b;
    
}
//aqui
node *rotateDoubleLeft(node *root){


}
//aqui
node *rotateLeftRight(node *root){



}


node* balance(node* root){ //no com cb > = 2 // -2

    //rotação à esquerda (desequilibrio a direita)
    if(root->cb > 1 && root->right->cb > 0) root = rotateLeft(root);

    else if(root->cb > 1 && root->right->cb < 0)
  
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