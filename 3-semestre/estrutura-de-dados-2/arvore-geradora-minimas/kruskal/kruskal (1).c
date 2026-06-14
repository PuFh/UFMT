#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#define INT_INFINITE INT_MAX

typedef int TIPOPESO;

typedef struct adjacencia{
    int vertice;
    TIPOPESO peso;
    struct adjacencia *prox;
} ADJACENCIA;

typedef struct vertice{
    int grau;
    /* Dados armazenados vao aqui */
    ADJACENCIA *cab;
} VERTICE;

typedef struct grafo {
    int vertices;
    int arestas;
    VERTICE *adj;
} GRAFO;


long long custo_total_agm = 0;

typedef struct {
    int u, v;
    TIPOPESO peso;

} ARESTA_K;

/* Criando um grafo */
GRAFO *criarGrafo (int v) {
    GRAFO *g = (GRAFO *) malloc(sizeof(GRAFO));
    
    g->vertices     = v;
    g->arestas      = 0;
    g->adj          = (VERTICE *) malloc(v*sizeof(VERTICE));
    int i;
    
    for (i=0; i < v; i++) {
        g->adj[i].cab = NULL;
        g->adj[i].grau = 0;
    }

    return g;
}

ADJACENCIA *criaAdj(int v,int peso){
    ADJACENCIA *temp = (ADJACENCIA *) malloc(sizeof(ADJACENCIA));
    temp->vertice   = v;
    temp->peso      = peso;
    temp->prox      = NULL;
    return (temp);
}

ADJACENCIA *inseriListAdj(ADJACENCIA *adj, int vi, int vf, TIPOPESO p)
{

    ADJACENCIA *ant = adj;
    ADJACENCIA *atual = adj;
    int control = 0;

    ADJACENCIA *novo = criaAdj(vf, p);

    while (atual != NULL && atual->vertice < vf)
    {
        ant = atual;
        atual = atual->prox;
        control = 1;
    }
    if (ant == NULL && control == 0)
    {
        novo->prox = atual;
        
        return novo;
    }
    else if (control == 0)
    {
        novo->prox = atual;
        return novo;
    } else{
        novo->prox = atual;
        ant->prox = novo;
    }

    return adj;
}

bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p){
    if (!gr) return false;
    if((vf < 0) || (vf >= gr->vertices)) return false;
    if((vi < 0) || (vi >= gr->vertices)) return false;
    gr->adj[vi].cab = inseriListAdj(gr->adj[vi].cab, vi, vf, p);
    gr->adj[vf].cab = inseriListAdj(gr->adj[vf].cab, vf, vi, p);
    gr->arestas++;

    return true;
}

int comp_arestas(const void *a, const void *b) { 
ARESTA_K *a1 = (ARESTA_K *)a;
ARESTA_K *a2 = (ARESTA_K *)b;
if (a1->peso < a2->peso) return -1;
if (a1->peso > a2->peso) return 1;

return 0;

}

int find_set(int i, int *pai) {

if (pai[i] == i) return i;
return pai[i] = find_set(pai[i], pai);

}

void union_set(int u, int v, int *pai, int *rank) {
int root_u = find_set(u, pai);
int root_v = find_set(v, pai);
if (root_u != root_v) {
    if(rank[root_u] < rank[root_v]) { pai[root_u] = root_v; }
    else if (rank[root_u] > rank[root_v]) { pai[root_v] = root_u; }
    else {
        pai[root_v] = root_u;
        rank[root_u]++;
    }
}
}


void imprime(GRAFO *gr){
    printf("Vertices: %d. Arestas: %d, \n", gr->vertices,gr->arestas);
    
    int i;
    for(i=0;i<gr->vertices; i++){
        printf("v%d: ",i);
        ADJACENCIA *ad = gr->adj[i].cab;
        while(ad){
            printf("v%d(%d) ", ad->vertice,ad->peso);
            ad = ad->prox;
        }
        
        printf("\n");
    }
}

// ----------- KRUSKAL ---------------------------

void agm_kruskal(GRAFO *gr, int orig, int *pai){
ARESTA_K *todas_arestas = (ARESTA_K *)malloc(gr->arestas * sizeof(ARESTA_K));

if (!todas_arestas) {
    printf("Erro de alocacao de memoria para arestas.\n");
    return;

 }
 // extraindo todas as arestas da lista de adjacencia
int k = 0;
for (int i = 0; i < gr->vertices; i++) {
ADJACENCIA *adj = gr->adj[i].cab;
while (adj) {

    if (i < adj->vertice) { // evita duplicidade
        todas_arestas[k].u = i;
        todas_arestas[k].v = adj->vertice;
        todas_arestas[k].peso = adj->peso;
        k++;
    }
    adj = adj->prox;
}


}


qsort(todas_arestas, k, sizeof(ARESTA_K), comp_arestas);

int *rank = (int *)calloc(gr->vertices, sizeof(int));
for (int i = 0; i < gr->vertices; i++) pai[i] = i;
custo_total_agm = 0;
int arestas_na_arvore = 0;

//construcao da arvore geradora minima
for (int i = 0; i < k; i++) {
    int u = todas_arestas[i].u;
    int v = todas_arestas[i].v;
    int peso = todas_arestas[i].peso;



    if (find_set(u, pai) != find_set(v, pai)) {

        union_set(u, v, pai, rank);
        custo_total_agm += peso;
        arestas_na_arvore++;

        if (arestas_na_arvore == gr->vertices - 1) break;


} 

}

free(todas_arestas);
free(rank);


}


int main(int argc, char *argv[]) {
    //caso nao seja passado argumento no terminal, assume-se o arquivo de NY por padrao
    const char *nome_arquivo = (argc >= 2) ? argv[1] : "USA-road-d.NY.gr";

    FILE *f = fopen(nome_arquivo, "r");
    if (!f) {
        printf("Erro ao abrir arquivo: %s\n", nome_arquivo);
        return 1;
    }
    printf("Carregando o grafo de: %s\n", nome_arquivo);
    char type;
    GRAFO *gr = NULL;

    while (fscanf(f, " %c", &type) != EOF) {
        if (type == 'c') {
            char buffer[512];
            fgets(buffer, sizeof(buffer), f); //ignora comentario
    } else if (type == 'p') {
        char sp[10];
        int n, m;
        fscanf(f, " %s %d %d", sp, &n, &m);
        gr = criarGrafo(n);

    } else if (type == 'a') {
        int u, v;
        TIPOPESO w;
        fscanf(f, " %d %d %d", &u, &v, &w);
        criaAresta(gr, u - 1, v - 1, w);

    }

}
fclose(f);

if(!gr) return 1;
printf("Vertices: %d / Arestas: %d\n", gr->vertices, gr->arestas);

int *pai = (int *)malloc(gr->vertices * sizeof(int));
clock_t inicio = clock();

agm_kruskal(gr, 0, pai);

clock_t fim = clock();
double tempo_gasto = (double)(fim-inicio) / CLOCKS_PER_SEC;

FILE *out = fopen("resultado_kruskal.txt", "a");
if(out) {
    fprintf(out, "Instancia processada: %s\n", nome_arquivo);
    fprintf(out, "custo total da arvore: %lld\n", custo_total_agm);
    fprintf(out, "tempo de execucao do alg kruskal: %f segundos\n", tempo_gasto);
    fprintf(out, "\n\n");
    fclose(out);
    printf("resultados prontos!!\n");
    

}
    free(pai);
    return 0;
}