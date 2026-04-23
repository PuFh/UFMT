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

    maior = 0;
    ax = 0;
    for(int i = 0; i < TAM;i++){
        if(vetor[i] % 2 == 0){
            ax++;
        }else{
            if(ax > maior){
                maior = ax;
            }
            sequencia = maior;
            ax = 0;
        }
    }
    //pq? pq a variavel maior só atualiza no for quando a variavel for impar, entao se n ultima posicao for par, n iriamos atualizar o maior
    //o ax teria a maior squencia mas o maior n
    if(ax > maior){
        maior = ax;
    }
    sequencia = maior;
    
    std::cout << "Maior Sequencia: "<<sequencia<<std::endl;
}
