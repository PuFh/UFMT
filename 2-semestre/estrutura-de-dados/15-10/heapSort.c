#include <stdio.h>

typedef struct {
    int *dados;
    int tamaho;
} Heap;

void ordenacao(Heap *h, int i) {
    int mEnor = i; //pai
    int esq = 2 * i + 1; //filho esq
    int dir = 2 * i + 2; //filho dir

    if (esq < h->tamaho && h->dados[esq] < h->dados[mEnor])
        mEnor = esq;

    if (dir < h->tamaho && h->dados[dir] < h->dados[mEnor])
        mEnor = dir;

    if (mEnor != i) {
        int v_aux = h->dados[i];
        h->dados[i] = h->dados[mEnor];
        h->dados[mEnor] = v_aux;
        ordenacao(h, mEnor);
    }
}

void heapSort(int arr[], int n) {
    Heap h;
    h.dados = arr;
    h.tamaho = n;

    for (int i = h.tamaho / 2 - 1; i >= 0; i--)
        ordenacao(&h, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = h.dados[0];
        h.dados[0] = h.dados[i];
        h.dados[i] = temp;

        h.tamaho--; 
        ordenacao(&h, 0);
    }
}

void printVetor(int v_dados[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", v_dados[i]);
    printf("\n");
}

int main() {
    int vetor[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    heapSort(vetor, n);

    printVetor(vetor, n);

    return 0;
}