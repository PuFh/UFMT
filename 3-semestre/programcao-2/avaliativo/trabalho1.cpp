/*
Em um vetor de 15 números, identifique e exiba a maior sequência de números pares
consecutivos.
*/
#include <iostream>

#define TAM 15

int main(){
    int vetor[TAM];
    int maior,ax,sequencia;

    for(int i = 0; i < TAM; i++){
        std::cout << "Digite o valor na posicao "<< i+1 <<": ";
        std::cin >> vetor[i];
    }

    std::cout <<"\n-----------\n\n";
    std::cout << "[";
    for(int i = 0; i < TAM; i++){
        std::cout <<vetor[i]<<" ";
    }
    std::cout << "]\n";

    //alteracoes
    int ax_indice,maior_indice,ind_inicio,ind_fim;
    ax_indice = 0;
    maior_indice= 0;
    ind_inicio = 0;
    ind_fim = 0;
    //-----
    maior = 0;
    ax = 0;
    for(int i = 0; i < TAM;i++){
        if(vetor[i] % 2 == 0){
            if(ax == 0){
                ind_inicio = i;
            }
            ax++;
        }else{
            ind_fim = i-1;
            if(ax > maior){
                maior = ax;
            }
            sequencia = maior;
            ax = 0;
        }
    }
    //att fim
    if(ax > maior){
        maior = ax;
    }
    sequencia = maior;
    
    std::cout << "Maior Sequencia: "<<sequencia<<std::endl;

    std::cout << "Inicio: "<<ind_inicio<<", fim: "<<ind_fim<<std::endl;
}
