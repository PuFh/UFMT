//Lista é um estrutura com maior liberdade
//Voce n conseue colocar um valor em qualquer posicao, mas voce pode mover todos os valores da lista para atribuir em um posicao N.
/*

@file lisa.c
#include <stdio.h>

*/
//-------CRIANDO BIBLIOTECA DE LISTAS------------


//definicao de biblioteca
#ifndef __LISTA_H__
#define __LISTA_H__

#include <stdio.h>
#include <stdlib.h>

//constante
#define N 10

//Definecao da estrutura
struct est_lista{
    int lista[N];
    int contador;
};
typedef struct  est_lista tipo_lista;//seria definir "apelido" de est_lista


//prototipo
int insereInicioLista(tipo_lista*,int);
int insereFimLista(tipo_lista*, int, int);
int isenrePosLista(tipo_lista*, int, int);//2o parametro

int removeInicioLista(tipo_lista*);
int removeFimLista(tipo_lista*);
int removePosLista(tipo_lista*);

int buscaValorLista(tipo_lista, int);
int retornaValorPosicaoLista(tipo_lista, int);
int atualizaValoresLista(tipo_lista*,int, int);//parametro inteiro sao valor
int quantidadeValoresLista(tipo_lista);
int listaVazia(tipo_lista);
int lista_cheia(tipo_lista);
void imprimeLista(tipo_lista);


#endif