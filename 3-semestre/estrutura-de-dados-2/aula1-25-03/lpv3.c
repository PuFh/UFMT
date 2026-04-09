#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//estrutura da nossa arvore
typedef struct no{
    int valor;
    struct no* esquerda;
    struct no* direita;
}no;

//prototipos das funcoes
no* novoNo(int);
no* insereNo(no*,int);


int main(){
    no* raiz;
    raiz = novoNo(40);
    raiz = insereNo(raiz, 20);
    raiz = insereNo(raiz, 60);
    raiz = insereNo(raiz, 10);

    int valor = 20;
    if(buscaNo(raiz, valor)){
        printf("%d está presente na árvore!\n", valor);
    } else {
        printf("%d não está presente na árvore.\n", valor);
    }

    return 0;
}

//novo No da raiz
no* novoNo(int v){
    no* novo = (no*)malloc(sizeof(no));

    //cria um novo nó que n aponta para nada, seria um no deslocado da raiz ou a raiz principal
    novo->valor = v;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

//inserer no
no* insereNo(no* raiz, int v){
    // caso a raiz esteja vazia
    if(raiz == NULL){
        return novoNo(v);
    }

    // n esta vazia, entao iremos comparar
    if(v < raiz->valor){  
        raiz->esquerda = insereNo(raiz->esquerda, v);
    } else if(v > raiz->valor){
        raiz->direita = insereNo(raiz->direita, v);
    }

    return raiz;
}

int buscaNo(no* raiz, int v){
    //elemento não está na árvore
    if(raiz == NULL){
        return 0;
    }

    // encontrou o elemento
    if(v == raiz->valor){
        return 1;
    }

    if(v < raiz->valor){
        return buscaNo(raiz->esquerda, v);
    }

    return buscaNo(raiz->direita, v);
}
