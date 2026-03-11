#include "stdlib.h"
#include "stdio.h"

#define MAX 100

void heapify(int arr[], int n, int i){
    int maior = i;
    int filhoEs = 2*i + 1;
    int filhoDi = 2*i +2;
    int ax;
    if(filhoEs > filhoDi){
        ax = filhoEs;
    }else{
        ax = filhoDi;
    }
    if(maior < ax){
        maior = ax;
    }
}
void heapSort(int arr[], int n){

}

int main(){
    int heap[MAX] = {5,3,6,12,8};
    int n = 5;

    heapSort(heap, n);

    for(int i = 0; i < n; i++){
        printf("%d ",heap[i]);
    }
    return 0;
}