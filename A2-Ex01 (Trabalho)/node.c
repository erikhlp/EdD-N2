#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *inserir(Node *raiz, int novoValor){
    if(raiz == NULL)
        return criar(novoValor);

    if (novoValor < raiz->valor )
        raiz->esq = inserir(raiz->esq, novoValor);

    if (novoValor > raiz->valor )
        raiz->dir = inserir(raiz->dir, novoValor);

    return raiz;
}

Node *criar(int novoValor){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->valor = novoValor;
    temp->esq = temp->dir = NULL;
    return temp;
}

void preOrder(Node *raiz){
    if (raiz != NULL) {
        printf("Pre Order %d\n", raiz->valor);
        preOrder(raiz->esq);
        preOrder(raiz->dir);
    }

}

void inOrder(Node *raiz){
    if (raiz != NULL) {
        inOrder(raiz->esq);
        printf("In Order %d\n", raiz->valor);
        inOrder(raiz->dir);
    }
}

void posOrder(Node *raiz){
    if (raiz != NULL) {
        inOrder(raiz->esq);
        inOrder(raiz->dir);
        printf("Pos Order %d\n", raiz->valor);
    }

}

void removerMaior(){
    // 2 dos 3 casos de remocao
    //    - folha
    //    - filho
}
