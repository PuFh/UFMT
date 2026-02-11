#include "stdlib.h"
#include "stdio.h"

typedef struct arvore_binaria{
    int valor;
    struct arvore_binaria* fEsq;
    struct arvore_binaria* fDir;
}arvore_binaria;

//inicializacao
//procedimento recursivo de colocar o valor na posicao

//PROTOTIPO
int insercao(arvore_binaria*, int);

int main(){
    arvore_binaria tree;

    insercao(&tree,15);
    insercao(&tree,20);
    insercao(&tree,8);

    printf("correto");
    printf("%d",tree.valor);
    printf("%d",tree.fEsq->valor);

    return 0;
}

int insercao(arvore_binaria *temp, int v){
    //caso unico, em que estamos na raiz
    
    if(temp == NULL){
        //aloca memoria e guarda
        temp = (arvore_binaria*)malloc(sizeof(arvore_binaria*));
        temp->valor = v;
        temp->fDir = NULL;
        temp->fEsq = NULL;
    }else{
        if(v > temp->valor){//filho direto
            insercao(temp->fDir, v);
        }
        else{
            insercao(temp->fEsq, v);
        }
    }

    
}