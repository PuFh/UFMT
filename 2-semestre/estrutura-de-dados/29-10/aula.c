#include <stdio.h>
#include <stdlib.h>


//Prototipo de funcoes
int func_copia(int param);
int fun_ref(int *param);
int *aloca_inteiro();

int main(){
    int valor;
    int *novo_valor;

    printf("Informe um valor inteiro: ");
    scanf("%d",&valor);

    //chamada da funcao com o parametro por COPIA
    func_copia(valor);
    printf("Valor apos chamada fa funcao com parametro por COPIA: %d\n",valor);
    printf("\n");
    //Chamada da funcao com parametro por REFERENCIA
    fun_ref(&valor);
    printf("Valor apos chamada da funcao co parametro por REFERENCIA: %d\n",valor);

    //Funcao que aloca um novo inteiro na memoria
    novo_valor = aloca_inteiro();
    printf("Valor informado pelo usuario usando a funcao aloca_inteiro: %d\n",*novo_valor);
    return EXIT_SUCCESS;
}

int func_copia(int param){
    printf("execucao da funcao com parametro por copia\n");
    printf("Valor do parametro recebido = %d\n",param);
    param = param*2;
    printf("O valor do parametro dobrado = %d\n",param);
    return 1;
}
int fun_ref(int *param){
    printf("execucao da funcao com parametro por REFERENCIA");
    printf("Valor do parametro recebido = %d\n",*param);
    *param = *param * 2;
    printf("Valor do parametro dobrado = %d\n",*param);
    return 1;
}

int *aloca_inteiro(){
    int tam, i;
    printf("Tamanho do vetor: ");
    scanf("%d",&tam);
    int *novo_vet_inteiro;//ponteiro declarada
    // aloca memoria
    novo_vet_inteiro = (int*) malloc(sizeof(int)*tam);
    for(i = 0; i<tam; i++){
        printf("Informe um novo valor: ");
        scanf("%d", &novo_vet_inteiro[i]);
    }
    int *pt_teste;
    pt_teste = &novo_vet_inteiro[3];//"cria um novo ponteiro a partir do nov_ve_inteiro da posicao 3 até a sua ultima, ou seja, o [3] do vet é [0] do pt_testesc"
    printf("O valor no indice %d eh %d\n",i,*pt_teste);

    return novo_vet_inteiro;
}