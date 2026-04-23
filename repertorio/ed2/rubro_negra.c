#include <stdio.h>
#include <stdlib.h>

enum COR { VERMELHO, PRETO };

typedef struct sNo {
    int chave;
    int cor;
    struct sNo *esq, *dir, *pai;
} TNo;

// --- FUNÇÕES AUXILIARES ---

TNo* criaNo(int chave) {
    TNo* novo = (TNo*)malloc(sizeof(TNo));
    novo->chave = chave;
    novo->cor = VERMELHO; // Todo nó novo nasce vermelho
    novo->esq = novo->dir = novo->pai = NULL;
    return novo;
}

// Rotação à Esquerda
void rotEsq(TNo **raiz, TNo *x) {
    TNo *y = x->dir;
    x->dir = y->esq;
    if (y->esq != NULL) y->esq->pai = x;
    y->pai = x->pai;
    if (x->pai == NULL) *raiz = y;
    else if (x == x->pai->esq) x->pai->esq = y;
    else x->pai->dir = y;
    y->esq = x;
    x->pai = y;
}

// Rotação à Direita
void rotDir(TNo **raiz, TNo *y) {
    TNo *x = y->esq;
    y->esq = x->dir;
    if (x->dir != NULL) x->dir->pai = y;
    x->pai = y->pai;
    if (y->pai == NULL) *raiz = x;
    else if (y == y->pai->esq) y->pai->esq = x;
    else y->pai->dir = x;
    x->dir = y;
    y->pai = x;
}

// --- AJUSTE PÓS-INSERÇÃO ---

void consertaInsercao(TNo **raiz, TNo *z) {
    while (z != *raiz && z->pai->cor == VERMELHO) {
        if (z->pai == z->pai->pai->esq) {
            TNo *tio = z->pai->pai->dir;
            if (tio != NULL && tio->cor == VERMELHO) { // Caso 1: Tio é Vermelho
                z->pai->cor = PRETO;
                tio->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                z = z->pai->pai;
            } else {
                if (z == z->pai->dir) { // Caso 2: Z é filho da direita
                    z = z->pai;
                    rotEsq(raiz, z);
                }
                // Caso 3: Z é filho da esquerda
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                rotDir(raiz, z->pai->pai);
            }
        } else { // Simétrico para o lado direito
            TNo *tio = z->pai->pai->esq;
            if (tio != NULL && tio->cor == VERMELHO) {
                z->pai->cor = PRETO;
                tio->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                z = z->pai->pai;
            } else {
                if (z == z->pai->esq) {
                    z = z->pai;
                    rotDir(raiz, z);
                }
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                rotEsq(raiz, z->pai->pai);
            }
        }
    }
    (*raiz)->cor = PRETO; // Regra 2
}

void insere(TNo **raiz, int chave) {
    TNo *z = criaNo(chave);
    TNo *y = NULL;
    TNo *x = *raiz;

    while (x != NULL) {
        y = x;
        if (z->chave < x->chave) x = x->esq;
        else x = x->dir;
    }
    z->pai = y;
    if (y == NULL) *raiz = z;
    else if (z->chave < y->chave) y->esq = z;
    else y->dir = z;

    consertaInsercao(raiz, z);
}

void imprime(TNo *h, int nivel) {
    if (h != NULL) {
        imprime(h->dir, nivel + 1);
        for (int i = 0; i < nivel; i++) printf("    ");
        printf("%d(%s)\n", h->chave, h->cor == VERMELHO ? "V" : "P");
        imprime(h->esq, nivel + 1);
    }
}

int main() {
    TNo *raiz = NULL;
    int valores[] = {10, 20, 30, 15, 25};
    for(int i=0; i<5; i++) insere(&raiz, valores[i]);
    
    printf("Árvore Rubro-Negra Final:\n");
    imprime(raiz, 0);
    return 0;
}