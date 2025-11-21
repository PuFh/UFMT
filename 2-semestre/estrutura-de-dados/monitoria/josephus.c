#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Problema 1: Josephus

typedef struct No {
    char nome[100];
    struct No* prox;
} No;

typedef struct {
    No* cabeca;
    int tamanho;
} ListaCircular;

ListaCircular* criar_lista() {
    ListaCircular* lista = (ListaCircular*)malloc(sizeof(ListaCircular));
    lista->cabeca = NULL;
    lista->tamanho = 0;
    return lista;
}

void adicionar(ListaCircular* lista, char* nome) {
    No* novo = (No*)malloc(sizeof(No));
    strcpy(novo->nome, nome);
    
    if (lista->cabeca == NULL) {
        lista->cabeca = novo;
        novo->prox = novo;
    } else {
        No* atual = lista->cabeca;
        while (atual->prox != lista->cabeca) {
            atual = atual->prox;
        }
        atual->prox = novo;
        novo->prox = lista->cabeca;
    }
    lista->tamanho++;
}

No* obter_aleatorio(ListaCircular* lista) {
    int idx = rand() % lista->tamanho;
    No* atual = lista->cabeca;
    for (int i = 0; i < idx; i++) {
        atual = atual->prox;
    }
    return atual;
}

void remover_proximo(ListaCircular* lista, No* anterior, char* removido) {
    No* remover = anterior->prox;
    strcpy(removido, remover->nome);
    
    if (lista->tamanho == 1) {
        lista->cabeca = NULL;
        free(remover);
    } else {
        anterior->prox = remover->prox;
        if (remover == lista->cabeca) {
            lista->cabeca = remover->prox;
        }
        free(remover);
    }
    lista->tamanho--;
}

void josephus() {
    char arquivo[100];
    printf("Nome do arquivoo: ");
    if (scanf("%s", arquivo) != 1) return;
    
    FILE* f = fopen(arquivo, "r");
    if (!f) {
        printf("Erro ao abrir arquivoo!\n");
        return;
    }
    
    ListaCircular* lista = criar_lista();
    char nome[100];
    
    // lerr nomes do arquivoo
    while (fgets(nome, 100, f)) {
        nome[strcspn(nome, "\n")] = 0;
        if (strlen(nome) > 0) {
            adicionar(lista, nome);
        }
    }
    fclose(f);
    
    printf("\n=== PROBLEMA DE JOSEPHUS ===\n");
    printf("Total de soldados: %d\n\n", lista->tamanho);
    
    // escolha de incio
    printf("Opcoes de inicio:\n");
    printf("1. Primeiro soldado da lista\n");
    printf("2. Soldado aleatorio\n");
    printf("3. Informar nome do soldado\n");
    int opcao;
    scanf("%d", &opcao);
    getchar();
    
    No* atual = lista->cabeca;
    if (opcao == 2) {
        atual = obter_aleatorio(lista);
        printf("\nSoldado sorteado: %s\n", atual->nome);
    } else if (opcao == 3) {
        char nome_inicio[100];
        printf("Nome do soldado: ");
        fgets(nome_inicio, 100, stdin);
        nome_inicio[strcspn(nome_inicio, "\n")] = 0;
        
        No* temp = lista->cabeca;
        int encontrado = 0;
        for (int i = 0; i < lista->tamanho; i++) {
            if (strcmp(temp->nome, nome_inicio) == 0) {
                atual = temp;
                encontrado = 1;
                break;
            }
            temp = temp->prox;
        }
        if (!encontrado) {
            printf("Soldado nao encontrado! Usando o primeiro.\n");
        }
    }
    
    printf("\n=== INICIO DA ELIMINACAO ===\n\n");
    
    while (lista->tamanho > 1) {
        int k = (rand() % 10) + 1;
        printf("Numero sorteado: %d\n", k);
        
        // contar k posicoes
        No* anterior = atual;
        for (int i = 0; i < k - 1; i++) {
            anterior = anterior->prox;
        }
        
        char removido[100];
        No* proximo = anterior->prox->prox;
        remover_proximo(lista, anterior, removido);
        
        printf("Eliminado: %s\n", removido);
        printf("Restantes: %d\n\n", lista->tamanho);
        
        atual = proximo;
    }
    
    printf("=== RESULTADO ===\n");
    printf("Sobrevivente: %s\n", lista->cabeca->nome);
}