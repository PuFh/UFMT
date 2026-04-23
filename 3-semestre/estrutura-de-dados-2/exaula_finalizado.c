#include <stdio.h>
#include <stdlib.h>

typedef struct sNoA {
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
    struct sNoA *ant;
} TNoA;

TNoA* criaNo(int v);
void imprime(TNoA *nodo, int tab);
TNoA* busca(TNoA *no, int chave);
TNoA* insere(TNoA *raiz, int v);
TNoA* move_para_raiz(TNoA *n);
TNoA* tic(TNoA *x); // Rotdir
TNoA* tac(TNoA *x); // Rotesq

int main(void) {
    TNoA *raiz = NULL;
    int qt, value, x;

    if (scanf("%d", &qt) != 1) return 0;
    for (int i = 0; i < qt; i++) {
        if (scanf("%d", &value) != 1) break;
        raiz = insere(raiz, value);
    }

    if (scanf("%d", &x) != 1) return 0;
    raiz = busca(raiz, x);

    imprime(raiz, 0);
    return 0;
}

TNoA* criaNo(int v) {
    TNoA* novo = (TNoA*)malloc(sizeof(TNoA));
    if (novo) {
        novo->chave = v;
        novo->esq = novo->dir = novo->ant = NULL;
    }
    return novo;
}

void imprime(TNoA *nodo, int tab) {
    if (nodo != NULL) {
        imprime(nodo->dir, tab + 2);
        for (int i = 0; i < tab; i++) printf(" ");
        printf("%d\n", nodo->chave);
        imprime(nodo->esq, tab + 2);
    }
}

// Rotação TIC (Direita)
TNoA* tic(TNoA *x) {
    TNoA *y = x->ant;
    y->esq = x->dir;
    if (x->dir) x->dir->ant = y;
    x->ant = y->ant;
    if (y->ant) {
        if (y == y->ant->esq) y->ant->esq = x;
        else y->ant->dir = x;
    }
    x->dir = y;
    y->ant = x;
    return x;
}

// Rotação TAC (Esquerda)
TNoA* tac(TNoA *x) {
    TNoA *y = x->ant;
    y->dir = x->esq;
    if (x->esq) x->esq->ant = y;
    x->ant = y->ant;
    if (y->ant) {
        if (y == y->ant->esq) y->ant->esq = x;
        else y->ant->dir = x;
    }
    x->esq = y;
    y->ant = x;
    return x;
}

TNoA* move_para_raiz(TNoA *n) {
    if (!n) return NULL;
    while (n->ant != NULL) {
        TNoA *pai = n->ant;
        TNoA *avo = pai->ant;

        if (avo == NULL) { // Caso Simples
            if (n == pai->esq) tic(n);
            else tac(n);
        } else if (n == pai->esq && pai == avo->esq) { // TIC-TIC
            tic(pai);
            tic(n);
        } else if (n == pai->dir && pai == avo->dir) { // TAC-TAC
            tac(pai);
            tac(n);
        } else if (n == pai->dir && pai == avo->esq) { // TIC-TAC
            tac(n);
            tic(n);
        } else { // TAC-TIC
            tic(n);
            tac(n);
        }
    }
    return n;
}

TNoA* insere(TNoA *raiz, int v) {
    if (!raiz) return criaNo(v);

    TNoA *atual = raiz;
    TNoA *pai = NULL;

    while (atual != NULL) {
        pai = atual;
        if (v < atual->chave) atual = atual->esq;
        else if (v > atual->chave) atual = atual->dir;
        else return move_para_raiz(atual);
    }

    TNoA *novo = criaNo(v);
    novo->ant = pai;
    if (v < pai->chave) pai->esq = novo;
    else pai->dir = novo;

    return move_para_raiz(novo);
}

TNoA* busca(TNoA *raiz, int chave) {
    if (!raiz) return NULL;
    TNoA *atual = raiz;
    TNoA *ultimo = raiz;

    while (atual != NULL) {
        ultimo = atual;
        if (chave == atual->chave) return move_para_raiz(atual);
        if (chave < atual->chave) atual = atual->esq;
        else atual = atual->dir;
    }
    return move_para_raiz(ultimo);
}