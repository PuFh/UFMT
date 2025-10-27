#include <stdio.h>
#include <stdlib.h>

//ponteiro eh uma variavel especial, que guarda um endereco de memoria
//ponteiro é uma variável que guarda um ENDEREÇO DE MEMÓRIA
int main(){
    int valor;
    int *pt_valor;

    valor = 5;
    pt_valor = &valor; //pt_br recebe o endereço de memória de valor
    *pt_valor = 100; //Atualiza o valor da variável valor para 100

    printf("%p\n",&valor);
    printf("%p\n",&pt_valor);
    //ponteiro = (int*) malloc(sizeof(int));
    //estamo pedindo alocação de memoria e o espaço de memoria é do tamanho de um inteiro
    
    return 0;
}