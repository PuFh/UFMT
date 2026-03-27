#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* prox;
}no;

//prototipo
no* criaNo(int);
void imprimeLista(no*);
no* insereOrdem(no*, int);

//funcao principal
int main(){

    no* lista = criaNo(8);
    
    lista = insereOrdem(lista, 9);
    lista = insereOrdem(lista, 2);

    imprimeLista(lista);

}

//funcao cria um no
no* criaNo(int v){

    no* novo = (no*)malloc(sizeof(no));

    if(novo == NULL){
        printf("Error");
        return 0;
    }

    novo->valor = v;
    novo->prox = NULL;
    return novo;
}

//funcao imprime
void imprimeLista(no* li){
    if(li == NULL){
        printf(" NULL\nFim da Lista");
        return;
    }

    printf("%d -->",li->valor);
    imprimeLista(li->prox);
}

//funcao insere ordem
no* insereOrdem(no* li, int v){
    no* novo = criaNo(v);

    // caso 1: v menor que valor inicial da lista
    if(li == NULL || li->valor > v){
        novo->valor = v;
        novo->prox = li;
        li = novo;

        return li;
    }

    //caso 2: encontrar a posicao de li
    no* prox = li;
    no* ant = li;

    while(li != NULL && prox->valor < v){
        //avanca uma posicao e o ant fica uma posicao atras de prox
        ant = prox;
        prox = prox->prox;
    }

    ant->prox = novo;
    novo->prox = prox;

    return li;
}

