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


node* rotateRight(node* root){

    node *a = root, *b = a->left, *c = b->right;
    
    b->right = a;

    a->left = c;
    a->cb = 0;

    return b;
}

node* rotateLeft(node* root){
    
    node *a = root, *b = a->right, *c = b->left;

    b->left = a;

    a->right = c;

    //o pivô tem seu cb atualizado
    a->cb = 0;

    //a intenção é atualizar esse cb fora dessa função para não alterar cbs indevidamente numa rotação dupla
    return b;
    
}

node *rotateRightLeft(node *root){

    node *a = root, *b = a->right, *c = b->left; 

    a->right = rotateRight(b);

    //como na proxima rotação a nova raiz é c, que atualmente é filho de a:
    c = rotateLeft(a);

    //analiza cb antigo de c (que é a nova raiz), antes de alterar
    switch (c->cb){
        case 1:
            a->cb = -1;
            b->cb = 0;
            break;

        case 0:
            b->cb = 0;
            a->cb = 0;
            break;

        case -1:
            b->cb = 1;
            a->cb = 0;
            break;
        
        default: //para fins de debug
            printf("Erro de balanceamento\n");
            break;
    }
    //corrige cb da nova raiz
    c->cb = 0;
    return c;
}
//aqui
node *rotateLeftRight(node *root){

    node *a = root, *b = a->left, *c = b->right;

    a->left = rotateLeft(b);

    //como na proxima rotação a nova raiz é c, que atualmente é filho de a:
    c = rotateRight(a);

    //analiza cb "antigo" de c
    switch (c->cb){
        case 1:
            a->cb = 0;
            b->cb = -1;
            break;

        case 0:
            b->cb = 0;
            a->cb = 0;
            break;

        case -1:
            b->cb = 0;
            a->cb = 1;
            break;
        
        default: //para fins de debug
            printf("Erro de balanceamento\n");
            break;
    }
    //corrige cb da nova raiz
    c->cb = 0;
    return c;
}


//como orientado em aula, jeito mais simples para indicar desbalanceamento é utilizar ponteiro para flag que indica crescimento de lado da arvore
node* insert(node *root, int value, int* raised){
    if(!root){
        *raised = 1;
        return createNode(value); 
    } 
    
    //direciona descida
    if(value > root->value) {
        root->right = insert(root->right, value, raised);
        
        //verifica atualização de cb
        if(raised){
            switch (root->cb){

            case -1:
                root->cb = 0;
                raised = 0;
                break;

            case 0:
                root->cb = 1;
                raised = 1;
                break;

            case 1:
                raised = 0;
                if()

            default://via das duvidas
                printf("erro em algum lugar no balanceamento\n");
                break;
            }
        }
    //caso inserção esquerda
    } else {
        root->left = insert(root->left, value, raised);

        if(raised){
            switch (root->cb) {
            case -1: //para de propagar a verificação
                raised = 0;
                return rotate(root);

            case 0:
                root->cb = -1;
                raised = 1;
                break;

            case 1:
                raised = 0;
                root->cb = 0;
                break;

            default://via das duvidas
                printf("erro em algum lugar no balanceamento\n");
                break;
            }


        }

    }


}


void inOrder(node *root){

    if(!root) return;

    printf("[%d cb: %d]", root->value, root->cb);

    inOrder(root->left);

    inOrder(root->right);
    
}