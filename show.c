//Arquivo de implementacao auxiliar das funcoes de mostrar arvore
#include <stdio.h>
#include "node.h"

void infix(struct node *arv){
    if(arv != (struct node *)NULL){
        printf("%c ", arv->data);
        infix(arv->left);
        infix(arv->right);
    }
}

void central(struct node *arv){
    if(arv != (struct node *)NULL){
        central(arv->left);
        printf("%c ", arv->data);
        central(arv->right);
    }
}

void postfix(struct node *arv){
    if(arv != (struct node *)NULL){
        postfix(arv->left);
        postfix(arv->right);
        printf("%c ", arv->data);
    }
}