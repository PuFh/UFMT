#include <stdio.h>
#include <stdlib.h>

typedef struct vizinho {
    int id_vizinho;
    struct vizinho *prox;
} TVizinho;

typedef struct grafo {
    int id_vertice;
    TVizinho *prim_vizinho;
    struct grafo *prox;
} TGrafo;

/* Protótipos */
void libera_vizinhos(TVizinho *v);
TGrafo* busca_vertice(TGrafo* g, int x);

TGrafo *inicializa() {
    return NULL;
}

void imprime(TGrafo *g) {
    while (g != NULL) {
        printf("Vertice %d: ", g->id_vertice);
        TVizinho *v = g->prim_vizinho;
        while (v != NULL) {
            printf("%d ", v->id_vizinho);
            v = v->prox;
        }
        printf("\n");
        g = g->prox;
    }
}

void libera_vizinhos(TVizinho *v) {
    while (v != NULL) {
        TVizinho *temp = v;
        v = v->prox;
        free(temp);
    }
}

void libera(TGrafo *g) {
    while (g != NULL) {
        libera_vizinhos(g->prim_vizinho);
        TGrafo *temp = g;
        g = g->prox;
        free(temp);
    }
}

TGrafo* busca_vertice(TGrafo* g, int x) {
    while ((g != NULL) && (g->id_vertice != x)) {
        g = g->prox;
    }
    return g;
}

TGrafo *insere_vertice(TGrafo *g, int x) {
    TGrafo *p = busca_vertice(g, x);
    if (p == NULL) {
        p = (TGrafo*) malloc(sizeof(TGrafo));
        p->id_vertice = x;
        p->prox = g;
        p->prim_vizinho = NULL;
        g = p;
    }
    return g;
}

void insere_aresta_um_sentido(TGrafo *g, int v1, int v2) {
    TGrafo *p = busca_vertice(g, v1);
    TVizinho *novo = (TVizinho *) malloc(sizeof(TVizinho));
    novo->id_vizinho = v2;
    novo->prox = p->prim_vizinho;  // era p->prim_sozinho
    p->prim_vizinho = novo;
}

TVizinho* busca_aresta(TGrafo *g, int v1, int v2) {
    TGrafo *pv1 = busca_vertice(g, v1);
    TGrafo *pv2 = busca_vertice(g, v2);
    TVizinho *resp = NULL;

    if ((pv1 != NULL) && (pv2 != NULL)) {
        resp = pv1->prim_vizinho;
        while ((resp != NULL) && (resp->id_vizinho != v2)) {
            resp = resp->prox;
        }
    }
    return resp;
}

void insere_aresta(TGrafo *g, int v1, int v2) {
    TVizinho *v = busca_aresta(g, v1, v2);
    if (v == NULL) {  // era != NULL
        insere_aresta_um_sentido(g, v1, v2);
        insere_aresta_um_sentido(g, v2, v1);
    }
}

int main() {
    TGrafo *g = inicializa();

    g = insere_vertice(g, 1);
    g = insere_vertice(g, 2);
    g = insere_vertice(g, 3);
    g = insere_vertice(g, 4);

    insere_aresta(g, 1, 2);
    insere_aresta(g, 1, 3);
    insere_aresta(g, 2, 4);
    insere_aresta(g, 3, 4);

    imprime(g);
    libera(g);
    return 0;
}