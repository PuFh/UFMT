#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// estrutura do campo minado

/*
    Celula
    eBomba 0 ou 1
    estaAberta 0 ou 1
    vizinhos 0 a 4
*/

typedef struct{
    int eBomba;
    int estaAberta;
    int vizinhos;
}Celula;

//variaveis globais

Celula jogo[10][10];
int l, c, tam = 10;

//procedimento para inicializar a matriz do jogo
void inicializarJogo(){
    for(l=0; l < tam; l++){
        for(c = 0; c < tam; c++){
            jogo[l][c].eBomba = 0;
            jogo[l][c].estaAberta = 0;
            jogo[l][c].vizinhos = 0;
        }
    }
}

//procedimento para sortear N bombas
void sortearBombas(int n){
    int i;
    srand(time(NULL));
    for(l = 0; i <= n; i++){
        l = rand() % tam;
        c = rand() % tam;
        //verifica se o sorteio caiu em uma posicao que já
        // tem bomba, para n haver um numero menor de bombas
        if(jogo[l][c].eBomba == 0){
            jogo[l][c].eBomba = 1;

        }else{
            i--;
        }
    }
}

/*  
    funcao que diz se um par de coordenadas eh valido ou n
    1 - eh valido
    0 - n eh valido
*/
int coordenadaEhValida(int l, int c){
    if(l >= 0 && l < tam && c >= 0 && c < tam)
        return 1;
    else
        return 0;


}

/*
    funcao que retorna a quantidade de bombas na 
    vizinhanca de l c
    n - quantidade de bombas
*/
int bombasVizinhas(int l, int c){
    /*  Verificar a posicao acima(l-1 e c), 
        posicao abaixo(l+1 e c), pos direita e esquerda
    */

    int quantidade = 0;

    if(coordenadaEhValida())
}

//procedimento para contar as bombas vizinhas
void contarBombas(){
    for(l=0; l < tam; l++){
        for(c = 0; c < tam; c++)
            jogo[l][c].vizinhos = -----;
    }
}

int main() {

    inicializarJogo();
    sortearBombas(10);

    printf("tudo certo!");
    return 0;
}        