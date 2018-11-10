#include <stdio.h>
#include "node.h"

int leaves(struct node *arv);
int leaves_alt(struct node *arv);

int main(){
    struct node *arv;
    cria_arvore(&arv);
    infix(arv);
    printf("\n");
    printf("%d leaves\n", leaves(arv));
    printf("%d leaves\n", leaves_alt(arv));
}

int leaves(struct node *arv){
    //o numeros de nos de uma arvore eh o numero de nos das suas duas subarvores mais a raiz das duas
    if(arv != (struct node *)NULL){
        if(arv->left == (struct node *)NULL && arv->right == (struct node *)NULL)
            return 1;
        else
            return leaves(arv->left) + leaves(arv->right);
    }
    else
        return 0;
}

int leaves_alt(struct node *arv){
    return arv == (struct node *)NULL ? 0 : arv->left == arv->right ? 1 : leaves_alt(arv->left) + leaves_alt(arv->right);
}