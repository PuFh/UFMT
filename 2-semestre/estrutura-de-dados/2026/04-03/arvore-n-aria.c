#include "stdlib.h"
#include "stdio.h"

#define TAM_NO 2
#define TAM_FILHO 3

typedef struct arvore_n_aria{
    int valores[TAM_NO];
    struct arvore_n_aria* filhos[TAM_FILHO];
}arvore_n_aria;

arvore_n_aria* criarNo(int chave){
    arvore_n_aria* novo = (arvore_n_aria*)malloc(sizeof(arvore_n_aria));

    //verifica se foi alocado memoria para esta variavel temp
    if(novo!=NULL){
        novo->valores[0] = chave;
        //colocando todo mundo como null, os filhos
        for(int i = 0; i < TAM_FILHO; i++){
            novo->filhos[i] = NULL;

            return novo;
        }
    }else{
        printf("Erro ao alocar novo!");
        return 0;
    }

}
