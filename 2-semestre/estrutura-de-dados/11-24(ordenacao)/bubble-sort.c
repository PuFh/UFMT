//METODO DE ORDENACAO

/*
comparacao de par em par.
-EM UMA PASSAGEM, ELE GARANTE QUE O MAIOR VALOR VA PARA O FINAL DA LISTA

*/
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int v[]);

int main(){
    int vet[5]={12,14,7,78,8};

    bubbleSort(vet);
}


void bubbleSort(int v[]){
    int i,ax;
  

    for(i = 0; i < 4; i++){
        if(v[i] > (v[i+1])){
            ax = v[i];
            v[i]= v[i+1];
            v[i+1] = ax;
        }
        printf("troca de valores: posicao %d e %d: %d e %d\n", i, i+1, v[i],v[i+1]);
    }

    i = 0;
    while (i < 5)
    {
        printf("vetor[%d]: %d\n", i, v[i]);
        i++;
    }
    
}
