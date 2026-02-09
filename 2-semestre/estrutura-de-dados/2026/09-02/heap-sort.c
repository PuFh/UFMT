#include "stdlib.h"
#include "stdio.h"

//NO HEAP SORTE, IREMOS UTILIZAR O HEAP MIN PARA PODERMOS ORDENAR UMA LISTA DO MENOR VALOR PARA O MAIOR VALOR

#define TAM 50

typedef struct hash{
    int vetor[TAM], contador;
}hash;

void inicializaHeap(hash*);
int indPai(int);
int indFEsq(int);
int indFDir(int);

int insereHeap(hash*, int);
int removeHeap(hash*);
int sobeHeap(hash*, int);
int desceHeap(hash*, int);
void imprimeHeap(hash*);


int main(){
    hash heap;

    inicializaHeap(&heap);

    /*
    insereHeap(&heap, 15);
    insereHeap(&heap, 8);
    insereHeap(&heap, 25);
    insereHeap(&heap, 9);
    */

    int v[5] = {15,12,6,1,2};

    for(int i = 0; i < 5; i++){
        insereHeap(&heap, v[i]);
    }
    
    imprimeHeap(&heap);

    //ordenando o vetor
    for(int i = 0; i > heap.contador; i++){
        v[i] = heap.vetor[i];
        removeHeap(&heap);
    }
    for(int i = 0; i <5;i++){
        printf("%d|",v[i]);
    }
    return 0;
}

void inicializaHeap(hash* heap){
    //mostrando que esta inicializado
    heap->contador = 0;
}

int indFEsq(int indice){
    return (2*indice + 1);
}

int indFDir(int indice){
    return (2*indice + 2);
}

int indPai(int indice){

    return (indice - 1)/2;
}

int desceHeap(hash* heap, int indice){
    // int ax;
    // if(heap->vetor[indice] < heap->vetor[indFEsq(heap->contador-1)] && heap->vetor[0] < heap->vetor[indFDir(heap->contador-1)]){
    //     //se ambos os filhos forem maiores que a raiz, vc ira comparar eles
    //     if(heap->vetor[indFEsq(heap->contador-1)] > heap->vetor[indFDir(heap->contador-1)]){
    //         ax = heap->vetor[0];
    //         heap->vetor[0] = heap->vetor[indFEsq(heap->contador-1)];
    //         heap->vetor[indFEsq(heap->contador-1)] = ax;
            
    //     }
    //     else{
    //         ax = heap->vetor[0];
    //         heap->vetor[0] = heap->vetor[indFDir(heap->contador-1)];
    //         heap->vetor[indFDir(heap->contador-1)] = ax;
    //     }
    // }
    // desceHeap(heap, **)

    int ind_menor;//alteracao para pegarmos o valor do menor indice

    //verifica se ha filho a esquerda
    if(indFEsq(indice) < heap->contador){
        ind_menor = indFEsq(indice);
        //verifica se ha filho a direita
        if(indFDir(indice) < heap->contador){
            //verifica se o filho esquerdo eh maior que o filho da direita
            if(heap->vetor[indFDir(indice)] < heap->vetor[indFEsq(indice)]){
                ind_menor = indFDir(indice);
            }
        }
    
        int ax;
        if(heap->vetor[ind_menor] < heap->vetor[indice]){
            ax = heap->vetor[indice];
            heap->vetor[indice] = heap->vetor[ind_menor];
            heap->vetor[ind_menor] = ax;
        }
        desceHeap(heap, ind_menor);
        return 1;
    }
    return 0;
}

int sobeHeap(hash* heap, int indice){//o int n seria o indice
    int temp;
    if(indice > 0){
        if(heap->vetor[indice] < heap->vetor[indPai(indice)]){
            temp = heap->vetor[indPai(indice)];
            heap->vetor[indPai(indice)] = heap->vetor[indice];
            heap->vetor[indice] = temp;
            sobeHeap(heap, indPai(indice));

            return 1;
        }
    }else{
        return 0;//ERROR
    }
}
int insereHeap(hash* heap, int n){
    //verifica se ha espaco no vetor heap
    if(heap->contador < TAM){
        heap->vetor[heap->contador++] = n;//neste caso, o contador mostra quantos valores tem, pois ele começa em zero
        
        //TODO: chamar a funcao subida
        sobeHeap(heap, heap->contador-1);//agora o contador se torna o indice da posicao 
        return 1; //sucesso
    }
    else{
        return 0;//Falha, mostrando na havendo espaco
    }
}

int removeHeap(hash* heap){

    if(heap->contador > 0){
        int removido = heap->vetor[0];
        heap->vetor[0] = heap->vetor[heap->contador-1];//   ou  --heap->contador
        desceHeap(heap, 0);
    
        return removido;

    }
    return 0;//erro
}

//Funcao que imprime o heap - para debugacao
void imprimeHeap(hash *heap) {
    int i;
    printf("Heap:\nQtd de elementos = %d\n[ ", heap->contador);
    for (i=0; i < heap->contador; i++) {
        printf("%d ", heap->vetor[i]);
    }
    printf("]\n");
}