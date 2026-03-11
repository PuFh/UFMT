#include "stdlib.h"
#include "stdio.h"

typedef struct no{
    int chave;
    struct no *esq;
    struct no *dir;
}no;

no *alocaNo(int valor){
    no *novo = malloc(sizeof(no));
    if(novo != NULL){
        novo->chave = valor;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

void insereNo(no **raiz, int valor){
    if(*raiz == NULL){
        *raiz = alocaNo(valor);
    }else{
        if(valor < (*raiz)->chave){
            insereNo(&(*raiz)->esq, valor);
        }
        else{
            insereNo(&(*raiz)->dir, valor);
        }
    }
}

void emOrdem(no *raiz){
    if (raiz != NULL){
        emOrdem(raiz->esq);
        printf("%d ",raiz->chave);
        emOrdem(raiz->dir);
    }
}

void preOrdem(no *raiz){
    if(raiz != NULL){
        printf("%d ",raiz->chave);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void posOrdem(no *raiz){
    if(raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->chave);
    }
}

no *busca(no *raiz, int valor){
    if(raiz == NULL)
        return NULL;
    if (valor == raiz->chave)
        return raiz;
    if(valor < raiz->chave)
        return busca(raiz->esq, valor);
    if( valor > raiz->chave)
        return busca(raiz->dir, valor);

}

int main() {
    no *raiz = NULL;


    insereNo(&raiz, 10);
    insereNo(&raiz, 7);
    insereNo(&raiz, 15);
    insereNo(&raiz, 3);
    insereNo(&raiz, 9);

    emOrdem(raiz);   // esperado: 3 7 9 10 15
    preOrdem(raiz);  // esperado: 10 7 3 9 15
    posOrdem(raiz);  // esperado: 3 9 7 15 10

    no *encontrado = busca(raiz, 7);
    if (encontrado != NULL)
        printf("Achou: %d\n", encontrado->chave);
    else
        printf("Nao encontrado!\n");

    return 0;
}
