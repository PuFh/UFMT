#include <stdlib.h>
#include <stdio.h>

typedef struct arvore_binaria {
    int valor;
    struct arvore_binaria* fEsq;
    struct arvore_binaria* fDir;
} arvore_binaria;

arvore_binaria* insercao(arvore_binaria* temp, int v) {
    if (temp == NULL) {
        temp = (arvore_binaria*)malloc(sizeof(arvore_binaria));
        temp->valor = v;
        temp->fDir = NULL;
        temp->fEsq = NULL;
        return temp;
    }
    if (v > temp->valor) {
        temp->fDir = insercao(temp->fDir, v);
    } else {
        temp->fEsq = insercao(temp->fEsq, v);
    }
    return temp;
}

void pre_ordem(arvore_binaria* temp) {
    if (temp != NULL) {
        printf("%d ", temp->valor);
        pre_ordem(temp->fEsq);
        pre_ordem(temp->fDir);
    }
}

void em_ordem(arvore_binaria* temp) {
    if (temp != NULL) {
        em_ordem(temp->fEsq);
        printf("%d ", temp->valor);
        em_ordem(temp->fDir);
    }
}

void pos_ordem(arvore_binaria* temp) {
    if (temp != NULL) {
        pos_ordem(temp->fEsq);
        pos_ordem(temp->fDir);
        printf("%d ", temp->valor);
    }
}

arvore_binaria* busca(arvore_binaria* temp, int v) {
    if (temp == NULL || temp->valor == v) return temp;
    if (v > temp->valor) return busca(temp->fDir, v);
    return busca(temp->fEsq, v);
}

int altura(arvore_binaria* temp) {
    if (temp == NULL) return -1;
    int esq = altura(temp->fEsq);
    int dir = altura(temp->fDir);
    return (esq > dir ? esq : dir) + 1;
}

void imprimir_nivel_especifico(arvore_binaria* temp, int nivel) {
    if (temp == NULL) return;
    if (nivel == 0) printf("%d ", temp->valor);
    else {
        imprimir_nivel_especifico(temp->fEsq, nivel - 1);
        imprimir_nivel_especifico(temp->fDir, nivel - 1);
    }
}

void imprimir_por_nivel(arvore_binaria* temp) {
    int h = altura(temp);
    for (int i = 0; i <= h; i++) {
        imprimir_nivel_especifico(temp, i);
        printf("\n");
    }
}

arvore_binaria* menor_no(arvore_binaria* node) {
    arvore_binaria* atual = node;
    while (atual && atual->fEsq != NULL) atual = atual->fEsq;
    return atual;
}

arvore_binaria* remocao(arvore_binaria* raiz, int v) {
    if (raiz == NULL) return raiz;
    if (v < raiz->valor) raiz->fEsq = remocao(raiz->fEsq, v);
    else if (v > raiz->valor) raiz->fDir = remocao(raiz->fDir, v);
    else {
        if (raiz->fEsq == NULL) {
            arvore_binaria* temp = raiz->fDir;
            free(raiz);
            return temp;
        } else if (raiz->fDir == NULL) {
            arvore_binaria* temp = raiz->fEsq;
            free(raiz);
            return temp;
        }
        arvore_binaria* temp = menor_no(raiz->fDir);
        raiz->valor = temp->valor;
        raiz->fDir = remocao(raiz->fDir, temp->valor);
    }
    return raiz;
}

int main() {
    arvore_binaria *tree = NULL;
    
    tree = insercao(tree, 15);
    tree = insercao(tree, 20);
    tree = insercao(tree, 8);
    tree = insercao(tree, 10);
    tree = insercao(tree, 5);

    printf("Em ordem: ");
    em_ordem(tree);
    printf("\n");

    printf("Altura: %d\n", altura(tree));

    printf("Por nivel:\n");
    imprimir_por_nivel(tree);

    tree = remocao(tree, 8);
    printf("Apos remover 8 (Em ordem): ");
    em_ordem(tree);
    printf("\n");

    return 0;
}