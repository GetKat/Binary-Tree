#include <stdio.h>
#include "node.h"

int nodes(struct node *arv);
int nodes_alt(struct node *arv);

int main(){
    struct node *arv;
    cria_arvore(&arv);
    infix(arv);
    printf("\n");
    printf("%d nodes\n", nodes(arv));
    printf("%d nodes\n", nodes_alt(arv));
}

int nodes(struct node *arv){
    //o numeros de nos de uma arvore eh o numero de nos das suas duas subarvores mais a raiz das duas
    if(arv != (struct node *)NULL)
        return nodes(arv->left) + nodes(arv->right) + 1;
    else
        return 0;
}

int nodes_alt(struct node *arv){
    return arv == (struct node *)NULL ? 0 : nodes_alt(arv->left) + nodes_alt(arv->right) + 1;
}