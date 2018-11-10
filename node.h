#ifndef NODE_H_
#define NODE_H_

struct node {
    char data;
    struct node *left, *right;
};

void cria_arvore(struct node **arv);

void infix(struct node *arv);
void postfix(struct node *arv);
void central(struct node *arv);

#endif