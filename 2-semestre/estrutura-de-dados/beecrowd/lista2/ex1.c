#include <stdio.h>
#include <stdint.h>  // para usar uint64_t

int main() {
    int T, N;
    uint64_t fib[61];  // usamos 61 posições (de 0 até 60)

    // valores iniciais
    fib[0] = 0;
    fib[1] = 1;

    // pré-calcula a sequência até o 60º termo
    for (int i = 2; i <= 60; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    scanf("%d", &T); // lê o número de casos de teste

    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        printf("Fib(%d) = %llu\n", N, fib[N]);
        // %llu é o formato para unsigned long long (mesmo tipo de uint64_t)
    }

    return 0;
}