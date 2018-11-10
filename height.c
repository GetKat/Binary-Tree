#include <stdio.h>
#include "node.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

int height(struct node *arv);

int main(){
    struct node *arv;
    cria_arvore(&arv);
    infix(arv);
    printf("\n");
    printf("altura: %d\n", height(arv));
}

int height(struct node *arv){
    int altura_aux(struct node *arv){
        if(arv != (struct node *)NULL){
            int a = altura_aux(arv->left);
            int b = altura_aux(arv->right);
            return max(a, b) + 1;
        }
        else
            return 0;
    }
    return altura_aux(arv) - 1;
}
