#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void delete_tree(struct node **arv);

int main(){
    struct node *arv;
    cria_arvore(&arv);
    infix(arv);
    delete_tree(&arv);
    infix(arv);
}

void delete_tree(struct node **arv){
    if(*arv != (struct node *)NULL){
        delete_tree(&(*arv)->left);
        delete_tree(&(*arv)->right);
        free(*arv);
        *arv = (struct node *)NULL;
    }
}
