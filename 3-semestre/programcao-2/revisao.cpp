#include <iostream>


const int TAM=100;

int main(){
    double array[TAM];

    double* a = array; //a apont aapra a posicao 0 do array
    //atribuicao
    for(int i = 0; i < TAM; i++){
        array[i] = 3+i*4;
    }
    for(int j = 0; j < TAM; j++){
        std::cout <<"Array["<<j<<"]: "<<*(a+j)<<std::endl;
    }

    return 0;
}