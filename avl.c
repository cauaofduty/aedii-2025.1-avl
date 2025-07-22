#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

//NEM TODAS AS FUNCOES DA AVL.C ESTAO NO ARQUIVO HEADER

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


node* rightRotate(node* root){

    node *a = root, *b = a->left, *c = b->right;
    
    b->right = a;

    a->left = c;
    a->cb = 0;

    //a intenção é atualizar esse cb fora dessa função para não alterar cbs indevidamente numa rotação dupla
    //retorna nova raiiz, b
    return b;
}

node* leftRotate(node* root){
    
    node *a = root, *b = a->right, *c = b->left;

    b->left = a;

    a->right = c;

    //o pivô tem seu cb atualizado
    a->cb = 0;

    //a intenção é atualizar esse cb fora dessa função para não alterar cbs indevidamente numa rotação dupla
    //retorna nova raiz, b
    return b;
    
}

node *doubleLeftRotation(node *root){

    node *a = root, *b = a->right, *c = b->left; 

    a->right = rightRotate(b);

    //como na proxima rotação a nova raiz é c, que atualmente é filho de a:
    c = leftRotate(a);

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
node *doubleRightRotation(node *root){

    node *a = root, *b = a->left, *c = b->right;

    a->left = leftRotate(b);

    //como na proxima rotação a nova raiz é c, que atualmente é filho de a:
    c = rightRotate(a);

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

//verifica rotação esquerda
node* leftRotationCheck(node *root){
    //caso cb = 1 faz rotação simples, do contrário, dupla
    if(root->right && root->right->cb == 1){

        root = leftRotate(root);

        //atualiza cb da nova raiz
        root->cb = 0;
    } 
    //retorna nova raiz com cb já atualizado
    else root = doubleLeftRotation(root);

    return root;
}

//verifica rotação direita
node* rightRotationCheck(node *root){
    //caso cb = -1 faz rotação simples, do contrário, dupla
    if(root->left && root->left->cb == -1){

        root = rightRotate(root);
        root->cb = 0;
    }

    else root = doubleRightRotation(root);

    return root;
}


//como orientado em aula, jeito mais simples para indicar desbalanceamento é utilizar ponteiro para flag que indica crescimento de lado da arvore
node* insert(node* root, int value, int* raised){
    if(!root){
        *raised = 1;
        return createNode(value); 
    } 
    
    //direciona descida
    if(value > root->value) {
        root->right = insert(root->right, value, raised);
        
        //verifica atualização de cb
        if(*raised){
            switch (root->cb){

            case -1: //inserção balanceou
                root->cb = 0;
                *raised = 0;
                break;

            case 0: //propaga balanceamento
                root->cb = 1;
                *raised = 1;
                break;

            case 1: //rotação disparada
                *raised = 0;
                root = leftRotationCheck(root);
                break;
            default://via das duvidas
                printf("erro em algum lugar no balanceamento na direita\n");
                break;
            }
        }
    //caso inserção esquerda
    } else if (value < root->value){
        root->left = insert(root->left, value, raised);

        if(*raised){
            switch (root->cb) {
            case -1: //para de propagar a verificação
                *raised = 0;
                root = rightRotationCheck(root);
                break;
            case 0:
                root->cb = -1;
                *raised = 1;
                break;

            case 1:
                *raised = 0;
                root->cb = 0;
                break;

            default://via das duvidas
                printf("erro em algum lugar no balanceamento na esquerda\n");
                break;
            }


        }

    }

    return root;
}

int greatest(node* root){//inserir o nó a procurar o maior sucessor (nesse caso, esquerdo do nó desejado)
    
    if(!root->right) return root->value;
    
    return greatest(root->right);
    
}

node* removeNode(node* root, int value, int *changed){

    if(!root) return NULL;
       
    if(value < root->value){

        root->left = removeNode(root->left, value, changed);

        if(*changed == 1){
            switch (root->cb){
                
            case 1://caso de desbalanceamento
                root = leftRotationCheck(root);
                break;

            case 0://caso de crescimento na direita
                root->cb = 1;
                *changed = 0;
                break;
            
            case -1:
                root->cb = 0;
                break;

            default:
                printf("erro no balanceamento da remocao esquerda\n");
                break;
            }
        }

    } else if (value > root->value){

        root->right = removeNode(root->right, value, changed);

        if(*changed == 1){
            switch (root->cb){

            case 1:
                root->cb = 0;
                *changed = 1;
                break;

            case 0://caso de crescimento na esquerda
                root->cb = -1;
                *changed = 0;
                break;
            
            case -1:
                *changed = 1;
                root = rightRotationCheck(root);
                break;
            default:
            printf("erro no balanceamento da remocao direita\n");
                break;
            }
        }
    //caso de valor encontrado
    } else {
        *changed = 1;

        //caso folha
        if (!root->left && !root->right){
            free(root);
            return NULL;
        } 
        //caso filho esquerdo unico
        else if (root->left && !root->right){

            //utiliza ponteiro auxiliar para salvar filho e limpar nó atual
            node *aux = root->left;
            free(root);
            return aux;
        }
        //caso filho direito unico
        else if (!root->left && root->right){
            
            //utiliza ponteiro auxiliar para salvar filho e limpar nó atual
            node *aux = root->right;
            free(root);
            return aux;
        }
        //caso de dois filhos
        else {
            //procura o valor predecessor no nó esquerdo
            root->value = greatest(root->left);
            root->left = removeNode(root->left,root->value, changed);
        }
    }

    return root;
}


void preOrder(node *root){

    if(!root) return;

    printf("[%d %d]", root->value, root->cb);
    
    preOrder(root->left);
    
    preOrder(root->right);
    
}