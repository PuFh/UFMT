
#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main(){
    tipo_lista minha_lista;
    minha_lista.contador = 0;

    //inicializacao de numeros pseudo aleatorios
    srand(0);

    insereInicioLista(&minha_lista, rand()%100);//o valor do resto entre rand()/100
    insereInicioLista(&minha_lista, rand()%100);
    insereInicioLista(&minha_lista, rand()%100);
    
    imprimeLista(minha_lista);

    return EXIT_SUCCESS;
}

/*
gcc lista.c -o lista.o -c |-c --> significa que o arquivo n esta pronto |lista.o -> compilação da biblioteca
ls lista*
gcc main.c lista.o -o main
./main
 */

 /* 
 gcc lista.c -o lista.o -c -g -->-g é para incluir as informções do debugador funcionar
 gcc main.c lista.o -o main -g
 */
//trocar o arquivo o program
