#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Problema 3: Verificador de parenteses

typedef struct NoPilha {
    char dado;
    struct NoPilha* prox;
} NoPilha;

typedef struct {
    NoPilha* topo;
} Pilha;

Pilha* criar_pilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void empilhar(Pilha* pilha, char c) {
    NoPilha* novo = (NoPilha*)malloc(sizeof(NoPilha));
    novo->dado = c;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

char desempilhar(Pilha* pilha) {
    if (pilha->topo == NULL) return '\0';
    
    NoPilha* temp = pilha->topo;
    char c = temp->dado;
    pilha->topo = pilha->topo->prox;
    free(temp);
    return c;
}

int pilha_vazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

int verificar_parenteses(char* str) {
    Pilha* pilha = criar_pilha();
    
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        
        // se for abretura, empilha
        if (c == '(' || c == '[' || c == '{') {
            empilhar(pilha, c);
        }
        // se for fechamento
        else if (c == ')' || c == ']' || c == '}') {
            if (pilha_vazia(pilha)) {
                return 0; // fechou sem abrir
            }
            
            char topo = desempilhar(pilha);
            
            // verificar se combina
            if ((c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{')) {
                return 0; // tipo errado
            }
        }
    }
    
    // pilha deve estar vazia no final
    int resultado = pilha_vazia(pilha);
    free(pilha);
    return resultado;
}

void testar_parenteses() {
    char str[1000];
    printf("Digite a string: ");
    scanf("%s", str);
    
    int resultado = verificar_parenteses(str);
    printf("Resultado: %d\n", resultado);
}

int main() {
    srand(time(NULL));
    
    int opcao;
    printf("Escolha o problema:\n");
    printf("1. Problema de Josephus\n");
    printf("2. Sistema de atendimento\n");
    printf("3. Verificador de parenteses\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    
    switch(opcao) {
        case 1:
            josephus();
            break;
        case 2:
            sistema_atendimento();
            break;
        case 3:
            testar_parenteses();
            break;
        default:
            printf("Opcao invalida!\n");
    }
    
    return 0;
}