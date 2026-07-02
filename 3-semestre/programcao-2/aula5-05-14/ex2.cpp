#include <iostream>

const int TAMANHO = 100;

int main(){
    double a[TAMANHO];
    double* aptr; //esse sera o nosso ponteiro de double que ira aponter para o array a e utilizaremos o proprio para a realizacao das operacoes de soma e media
    double soma, media;
    soma = 0.0;
    media = 0.0;
    aptr = a;//aptr agora aponta para o endereco da primeira posicao(a[0])

    for(int j=0; j < TAMANHO; j++){
        std::cin >> *(a+j);
        soma += *(aptr+j); //aqui basicamente estamos fazendoa aritmetica de ponteiro, o +j e algo curioso pois ele "muda sua atribuica" de valor conforme o tipo de variavel, em inteiros, ele pula 4 bytes, ja no double ela pula 8 bytes
    }
    media = soma/TAMANHO;
    //impressao
    /*
    for(int i=0; i < TAMANHO; i++){
        std::cout <<"Valor do vetor a["<<i<<"]: " <<a[i]<<std::endl;
    }
    */
    std::cout <<"Soma: "<<soma<<std::endl;
    std::cout <<"Media: "<<media<<std::endl;

    return 0;
}