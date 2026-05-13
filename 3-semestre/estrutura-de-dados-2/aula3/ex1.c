#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

//immplementacao de uma matriz esparsa, LVP - Matriz esparsa - Atividade 01

typedef struct No{
    int linha, coluna;
    struct No* prox;
}No;

typedef No* POINT;

typedef struct MATRIZ{
    POINT* A;
    int linhas;
    int colunas;
}MATRIZ;

int main(){

    return 0;
}