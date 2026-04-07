#include "stdio.h"
#include "stdlib.h"

typedef struct no{
    int valor;
    struct no* esq;
    struct no* dir;
}no;

no* criaNo(int v){
    no* novo = (no*)malloc(sizeof(no));

    if(novo == NULL){
        return 0;
    }

    novo->valor = v;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

int main(){
    no* raiz;

    raiz = criaNo(20);
    
}