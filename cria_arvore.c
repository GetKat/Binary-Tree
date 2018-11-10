#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void cria_arvore(struct node **arv);

int main(){
    struct node *arv;
    cria_arvore(&arv);
    infix(arv);
}

void cria_arvore(struct node **arv){
    char data;
    scanf(" %c", &data);
    if(data != '.'){
        *arv = (struct node *)malloc(sizeof(struct node));
        (*arv)->data = data;
        cria_arvore(&(*arv)->left);
        cria_arvore(&(*arv)->right);
    }
    else
        *arv = (struct node *)NULL;
}