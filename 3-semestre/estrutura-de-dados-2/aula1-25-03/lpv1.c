#include "stdio.h"
#include "stdlib.h"
//TODO: funcoes


//struct
typedef struct lista{
    int valor;
    struct lista* prox;
}lista;


//prototipo
lista* criaNo(int);
//lista* insereFim(lista*,int);
lista* insereInicio(lista*, int);
void imprime(lista*);
lista* insereOrdem(lista*,int);

//main
int main(){
    lista* head;

    head = criaNo(15);

    head = insereOrdem(head, 20);
    
    head = insereOrdem(head, 13);
    head = insereOrdem(head, 7);
    imprime(head);


}

lista* criaNo(int v){
    lista* novo = (lista*)malloc(sizeof(lista));

    if(novo == NULL){
        printf("erro ao alocar memoria!");
        return 0;
    }
    novo->valor = v;
    novo->prox = NULL;
    return novo;
}

lista* insereInicio(lista* li, int v){
    
    if(li == NULL){
        lista* novo = criaNo(v);
        return novo;
    }

    lista* novo = (lista*)malloc(sizeof(lista));
    novo->valor = v;
    novo->prox = li;
    return novo;
}


void imprime(lista* li){
    if(li == NULL){
        printf("--> NULL\nFim da Lista!");
        return;
    }
    printf("%d ",li->valor);
    imprime(li->prox);
}

lista* insereOrdem(lista* li, int v){
    //faz com que n precisemos alocar varias vezes espaco alocacao de memoria, como no if de ser menor que a cabeca e fora
    lista* novo = criaNo(v);

    if(li == NULL || li->valor > v){
        
        novo->prox = li;
        return novo;
    }


    lista* p = li;
    lista* q = li;

    novo->valor = v;
    novo->prox = li;

   

    while(p->prox != NULL && p->valor < novo->valor ){

        //avanca um bloco e faz com que o q fique sempre uma posicao anterior que o p
        q = p;
        p = p->prox;
    }

    novo->prox = q->prox;
    q->prox = novo;
    return li;

}

