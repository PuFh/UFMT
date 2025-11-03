//PILHA
#include <stdio.h>
#define TAM 10

int pilha[TAM], topo;

void inicializa();
void empilha(){
    int valor;
    topo = 0;

    printf("Valor: ");
    scanf("%d",&valor);
    pilha[topo] = valor;
}
void desempilha();
void imprimir();