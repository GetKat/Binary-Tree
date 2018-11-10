#include <stdio.h>
#include "node.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

void nodes_per_level(struct node *arv);
int height(struct node *arv);

int main(){
    struct node *arv;
    cria_arvore(&arv);
    infix(arv);
    printf("\n");
    nodes_per_level(arv);
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

void nodes_per_level(struct node *arv){
    int num_of_nodes_in_level(struct node *arv, int level, int cur){
        if(arv != (struct node *)NULL){
            if(level == cur)
                return 1;
            else
                return num_of_nodes_in_level(arv->left, level, cur + 1) + num_of_nodes_in_level(arv->right, level, cur + 1);
        }
        else
            return 0;
    }
    void print_nodes_in_level(struct node *arv, int level, int cur){
        if(arv != (struct node *)NULL){
            if(level == cur)
                printf("%c ", arv->data);
            else{
                print_nodes_in_level(arv->left, level, cur + 1);
                print_nodes_in_level(arv->right, level, cur + 1);
            }
        }
    }
    int h = height(arv);
    for(int i = 0; i <= h; i++){
        printf("nodes in level %d (%d nodes): ", i, num_of_nodes_in_level(arv, i, 0));
        print_nodes_in_level(arv, i, 0);
        printf("\n");
    }
}