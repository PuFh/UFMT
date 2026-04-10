#include "stdio.h"
#include "stdlib.h"

//estrutura do no da nossa arvore
typedef struct no{
    int valor;
    struct no *esquerdo,*direito;
}No;

//prototipo da funcoes
No* criaNo(int);
No* insereNo(No*, int);

int main(){
    No* arvore;

    arvore = criaNo(20);
}

No* criaNo(int v){
    No* novo = (No*)malloc(sizeof(No));
    
}