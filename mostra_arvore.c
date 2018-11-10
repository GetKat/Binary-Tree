#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void infix(struct node *arv);

int main(){
    struct node *arv;
    cria_arvore(&arv);
    infix(arv);
}

void infix(struct node *arv){
    if(arv != (struct node *)NULL){
        printf("%c ", arv->data);
        infix(arv->left);
        infix(arv->right);
    }
    else //opcional
        printf(". ");
}