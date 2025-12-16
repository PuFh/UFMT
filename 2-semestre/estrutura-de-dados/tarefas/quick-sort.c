#include <stdio.h>

void mostraVetor(int arr[], int tam) {
    printf("[");
    for (int i = 0; i < tam; i++) {
        printf("%d", arr[i]);
        if (i < tam - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int pArticionar(int arr[], int baixo, int alto) {
    int pivo = arr[alto]; 
    
    int j = (baixo - 1); 

    for (int i = baixo; i <= alto - 1; i++) { 
        if (arr[i] <= pivo) {
            j++; 
            
            int tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
        }
    }
    
    int tmp = arr[j + 1];
    arr[j + 1] = arr[alto];
    arr[alto] = tmp;
    
    return (j + 1);
}

void quickSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        
        int pi = pArticionar(arr, baixo, alto);

        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

int main() {
    int vetor_dados[] = {10, 7, 8, 9, 1, 5, 20}; 
    int n = sizeof(vetor_dados) / sizeof(vetor_dados[0]);

    printf("Vetor Antes:\n");
    mostraVetor(vetor_dados, n);
    
    quickSort(vetor_dados, 0, n - 1);
    
    printf("\nVetor depois:\n");
    mostraVetor(vetor_dados, n);
    
    return 0;
}