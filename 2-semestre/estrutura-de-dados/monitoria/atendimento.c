#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct NoFila {
    int id;
    char nome[100];
    struct NoFila* prox;
} NoFila;

typedef struct {
    NoFila* frente;
    NoFila* tras;
} Fila;

Fila* criar_fila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->frente = NULL;
    fila->tras = NULL;
    return fila;
}

void enfileirar(Fila* fila, int id, char* nome) {
    NoFila* novo = (NoFila*)malloc(sizeof(NoFila));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    
    if (fila->tras == NULL) {
        fila->frente = novo;
        fila->tras = novo;
    } else {
        fila->tras->prox = novo;
        fila->tras = novo;
    }
}

NoFila* desenfileirar(Fila* fila) {
    if (fila->frente == NULL) return NULL;
    
    NoFila* temp = fila->frente;
    fila->frente = fila->frente->prox;
    
    if (fila->frente == NULL) {
        fila->tras = NULL;
    }
    
    return temp;
}

int fila_vazia(Fila* fila) {
    return fila->frente == NULL;
}

void sistema_atendimento() {
    char arquivo[100];
    printf("Nome do arquivoo: ");
    scanf("%s", arquivo);
    
    FILE* f = fopen(arquivo, "r");
    if (!f) {
        printf("Erro ao abrir arquivoo!\n");
        return;
    }
    
    int n;
    fscanf(f, "%d", &n);
    
    Fila* fila = criar_fila();
    
    for (int i = 0; i < n; i++) {
        int id;
        char nome[100];
        fscanf(f, "%d ", &id);
        fgets(nome, 100, f);
        nome[strcspn(nome, "\n")] = 0;
        enfileirar(fila, id, nome);
    }
    fclose(f);
    
    // imprimir proximo sem remover
    if (!fila_vazia(fila)) {
        printf("Proximo: %s (ID: %d)\n", fila->frente->nome, fila->frente->id);
    }
    
    // atender todos
    while (!fila_vazia(fila)) {
        NoFila* cliente = desenfileirar(fila);
        printf("Atendendo: %s (ID: %d)\n", cliente->nome, cliente->id);
        free(cliente);
    }
    
    printf("Fila vazia!\n");
}