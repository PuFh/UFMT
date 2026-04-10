#include "stdio.h"
#include "stdlib.h"
#include "string.h"

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

no* insereNo(no* raiz, int v){
    //caso a raiz seja nula, n temos nada na arvore
    if(raiz == NULL){
        return criaNo(v);
    }

    if(v > raiz->valor && raiz != NULL ){
        raiz->dir = insereNo(raiz->dir, v);
    }
    else{
        raiz->esq = insereNo(raiz->esq, v);
    }

    return raiz;
}

//percurso preOrdem(no* raiz)
void preOrdem(no* raiz){
    if(raiz == NULL){
        return;
    }
    printf("%d\n",raiz->valor);
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}

//percurso em Ordem simetrica
void ordemSimetrica(no* raiz){
    if(raiz == NULL){
        return;
    }
    ordemSimetrica(raiz->esq);
    printf("%d\n",raiz->valor);
    ordemSimetrica(raiz->dir);
}

//percurso em pos ordem
void posOrdem(no* raiz){
    if (raiz == NULL)
    {   
        return;
    }

    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    printf("%d\n",raiz->valor);
    
}

void imprimirArvoreHelper(no* raiz, char* prefixo, int ultimo){
    if(raiz == NULL) return;

    printf("%s%s%d\n", prefixo, ultimo ? "└── " : "├── ", raiz->valor);

    char novoPrefixo[256];
    strcpy(novoPrefixo, prefixo);
    strcat(novoPrefixo, ultimo ? "    " : "│   ");

    imprimirArvoreHelper(raiz->esq, novoPrefixo, raiz->dir == NULL);
    imprimirArvoreHelper(raiz->dir, novoPrefixo, 1);
}

void imprimirArvore(no* raiz){
    if(raiz == NULL) return;
    printf("%d\n", raiz->valor);
    imprimirArvoreHelper(raiz->esq, "", raiz->dir == NULL);
    imprimirArvoreHelper(raiz->dir, "", 1);
}

int main(){
    no* raiz;

    raiz = criaNo(20);
    raiz = insereNo(raiz, 25);
    raiz = insereNo(raiz, 12);
    raiz = insereNo(raiz, 15);
    raiz = insereNo(raiz, 30);
    
    
    imprimirArvore(raiz);
    return 0;
}