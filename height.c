#include <stdio.h>
#include "node.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

int height(struct node *arv);
int height_alt(struct node *arv);

int main(){
    struct node *arv;
    cria_arvore(&arv);
    infix(arv);
    printf("\n");
    printf("altura: %d\n", height(arv));
    printf("altura: %d\n", height_alt(arv));
}

int height(struct node *arv){
    //"a altura de uma arvore eh definida por: 'a maior altura das suas subarvores mais 1(sua raiz)'"
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

//maneira alternativa de calcular altura
int height_alt(struct node *arv){
    if(arv != (struct node *)NULL){
        int a = height_alt(arv->left);
        int b = height_alt(arv->right);
        return max(a, b) + 1;
    }
    //height of a non-existent tree could be considered -1 for recursion purpuses
    else
        return -1; //will only be added once to the arithmetics
}