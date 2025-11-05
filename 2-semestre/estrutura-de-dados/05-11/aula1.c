
int main() {
    int arr[6] = {10, 20, 30, 40};
    int n = 4; // Número atual de elementos
    int pos = 1; // Posição para remover

    // Verificar se a posição é válida
    if (pos >= 0 && pos < n) {
        // Mover elementos para a esquerda
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--; // Diminuir a contagem de elementos
    }

    printf("Array apos remocao: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
