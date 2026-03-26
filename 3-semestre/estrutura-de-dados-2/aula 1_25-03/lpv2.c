#include "stdio.h"
#include "stdlib.h"

typedef struct lista{
    int valor;
    struct lista* prox;
}lista;

//Implemente a função que insere valores no fim da lista encadeada

//prototipo
lista* criaNo(lista*, int);
lista* insereFim(lista*,int);
lista* insereInicio(lista*, int);
void imprime(lista*);

int main(){
    lista* head;

    head = criaNo(head, 10);
    head = insereInicio(head, 13);
    
    head = insereFim(head, 20);
    imprime(head);
}

lista* criaNo(lista* li, int v){
    lista* novo = (lista*)malloc(sizeof(lista));

    if(novo==NULL){
        printf("Error ao alocar memoria dinamicamente!");
    }
    novo->valor = v;
    novo->prox = NULL;
    return novo;

}

//impressoa
void imprime(lista* li){

    if(li == NULL){
        printf(" NuLL\nFim da Lista!");
        return;
    }
    printf("%d --> ",li->valor);
    imprime(li->prox);
}

lista* insereInicio(lista* li, int v){
    //caso a lista esteja vazia
    if(li==NULL){
       lista* p =  criaNo(li, v);
       return p;
    }
    lista* novo = (lista*)malloc(sizeof(lista));
    novo->valor = v;
    novo->prox = li;
    return novo;


}

//insere no fim(O QUE VIEMOS FAZER)
lista* insereFim(lista* li, int v){
    //caso a nossa lista esteja vazia

    lista* novo = (lista*)malloc(sizeof(lista));

    lista* p = li;
    lista* q = li;

    while( q != NULL){
        p = q;
        q = q->prox;  
    }
    printf("aqui\n");
    if(q == NULL){
        p->prox = novo;
    }else{
        li = novo;
        return li;
    }
}