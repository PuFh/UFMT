#include <stdio.h>
#include <stdlib.h>
typedef struct sNoA
{
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
    struct sNoA *ant;
    // Se necessário pode adicionar elementos na struct

} TNoA;
//prototipos
TNoA* cria();
TNoA* criaNo(int);
void imprime(TNoA*, int);
TNoA* busca(TNoA*, int);
TNoA* insere(TNoA*,int);
TNoA* rotacao(TNoA*);
TNoA* rotdir(TNoA*);
TNoA* rotesq(TNoA*);


int main(void)  {
    TNoA *raiz;
    raiz = cria();
    int qt,value,x;
    scanf("%i",&qt);
    for(int i=0; i<qt;i++){
    scanf("%i",&value);
    raiz = insere(raiz,value);
    }
    scanf("%i",&x);
    raiz = busca(raiz, x);
    imprime(raiz,0);
    return 0;
}
// Se necessário, pode criar funções auxiliares
TNoA *cria(){
    return NULL;
}
TNoA* criaNo(int v){
    TNoA* novo = (TNoA*)malloc(sizeof(TNoA));
    if(novo == NULL){
        return 0;
    }
    novo->chave = v;
    novo->esq = NULL;
    novo->dir =NULL;
    novo->ant = NULL;
    
    return novo;

}
void imprime(TNoA *nodo, int tab){
    if (nodo != NULL)
    {
    imprime(nodo->esq, tab + 2);
    printf("%d\n", nodo->chave);
    imprime(nodo->dir, tab + 2);
    }
}
TNoA *busca(TNoA *no, int chave){
    // implemente seu código de busca aqui
}
TNoA *insere(TNoA *raiz, int v){
    TNoA* ax;
    ax = NULL;

    //inserindo no lugar correto
    if(raiz == NULL){
        return criaNo(v);
    }
    else if (v > raiz->chave){
        raiz->dir = insere(raiz->dir, v);
        ax = raiz;
    }
    else if (v < raiz->chave){
        raiz->esq = insere(raiz->esq,v);
        ax = raiz;
    }
    else{
        printf("Error, ja existe ou invalido");
        return 0;
    }
    raiz->ant = ax;
    //rotacoes
    raiz = rotacao(raiz);
    
    return raiz;
}
TNoA* rotacao(TNoA* p){
    TNoA* ax = p->ant;

    if(ax != NULL){
        if(ax->ant != NULL){
            //rotcao duplas

            if(ax->ant->dir == ax->ant){
                p = rotesq(p);
                p = rotesq(p);
                p = rotacao(p);
            }
            if(ax->ant->dir == ax->ant){
                p = rotdir(p);
                p = rotdir(p);
                p = rotacao(p);
            }
        }
        //rotacao simples
        else if (p->ant->dir == p){
            p = rotesq(p);
            p = rotacao(p);
        }
        else if (p->ant->esq == p){
            p = rotdir(p);
            p = rotacao(p);
        }
        
        
    }
    p->ant = NULL;
    return p;//que agora sera a raiz
}
TNoA* rotdir(TNoA* p){
    TNoA* ax = p->ant;

    ax->ant = p;
    p->esq = ax;
    ax->dir = p->esq;
    p->esq->ant = ax;
    p = rotacao(p);
}
TNoA* rotesq(TNoA* p){
    TNoA* ax = p->ant;

    ax->ant = p;
    p->esq = ax;
    ax->dir = p->esq;
    p->esq->ant = ax;
    p = rotacao(p);
    return p;
}

