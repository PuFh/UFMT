#include "stdlib.h"
#include "stdio.h"

#define MAX 100

void heapify(int arr[], int n, int i){
    int maior = i;
    int filhoEs = 2*i + 1;
    int filhoDi = 2*i +2;
    int ax;

    if(filhoEs < n && arr[filhoEs] > arr[maior]){
        maior = filhoEs;
    }
    if(filhoDi < n && arr[filhoDi] > arr[maior]){
        maior = filhoDi;
    }

    if(maior != i){
        ax = arr[i];
        arr[i] = arr[maior];
        arr[maior] = ax;
        heapify(arr, n, maior);
    }
}
void heapSort(int arr[], int n){
    int i, ax;
    for( i = n/2-1; i >= 0; i--){
        heapify(arr, n, i);
    }
    for(i = n-1; i > 0;i--){
        ax = arr[0];
        arr[0] = arr[i];
        arr[i] = ax;

        heapify(arr, i,0);
    }

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