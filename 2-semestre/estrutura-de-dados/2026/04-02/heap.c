#include "stdlib.h"
#include "stdio.h"

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
void imprimiHeap(hash*);


int main(){
    hash heap;

    inicializaHeap(&heap);
    
    insereHeap(&heap, 15);

    return 0;
}

void inicializaHeap(hash* heap){
    //mostrando que esta inicializado
    heap->contador = 0;
}

int indFesq(int indice){
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
    int ind_maior;
    //verifica se ha filho a esquerda
    if(indFEsq(indice) < heap->contador){
        ind_maior = indFEsq(indice);
        //verifica se ha filho a direita
        if(indFDir(indice) < heap->contador){
            //verifica se o filho esquerdo eh maior que o filho da direita
            if(heap->vetor[indFDir(indice)] > heap->vetor[indFEsq(indice)]){
                ind_maior = indFDir(indice);
            }
        }
    
        int ax;
        if(heap->vetor[ind_maior] > heap->vetor[indice]){
            ax = heap->vetor[indice];
            heap->vetor[indice] = heap->vetor[ind_maior];
            heap->vetor[ind_maior] = ax;
        }
        desceHeap(heap, ind_maior);
        return 1;
    }
    return 0;
}

int sobeHeap(hash* heap, int indice){//o int n seria o indice
    int temp;
    if(indice > 0){
        if(heap->vetor[indice] > heap->vetor[indPai(indice)]){
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