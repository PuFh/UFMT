#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define INT_MAX 32000
typedef int bool;
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

/* Criando um grafo */
GRAFO *criarGrafo(int v){
    GRAFO *g = (GRAFO *) malloc(sizeof(GRAFO));
    
    g->vertices = v;
    g->arestas = 0;//um vértice sem conexão
    g->adj = (VERTICE *) malloc(v*sizeof(VERTICE));
    
    for (int i = 0; i < v; i++){
        g->adj[i].cab = NULL;
        g->adj[i].grau=0;    
    }//fora do laço
    return g;
}

ADJACENCIA *criaAdj(int v,int peso){
    ADJACENCIA *temp = (ADJACENCIA*) malloc(sizeof(ADJACENCIA));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;
    return temp;
}

ADJACENCIA *inseriListAdj(ADJACENCIA *adj, int vi, int vf, TIPOPESO p){
    ADJACENCIA *ant = adj;
    ADJACENCIA *atual = adj;
    int control = 0;

    ADJACENCIA *novo = criaAdj(vf, p);

    while (atual != NULL && atual->vertice < vf){
        ant = atual;
        atual = atual->prox;
        control = 1;
    }
    if (ant == NULL && control == 0){
        novo->prox = atual;
        
        return novo;
    }else if (control == 0){
        novo->prox = atual;
        return novo;
    }else{
        novo->prox = atual;
        ant->prox = novo;
    }
    return adj;
}

bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p){
    if (!gr)
        return(false);
    if((vf<0) || (vf >= gr->vertices))
        return(false);
    if((vi<0) || (vf >= gr->vertices))
        return(false);
    
    gr->adj[vi].cab = inseriListAdj(gr->adj[vi].cab, vi, vf, p);
    gr->adj[vf].cab = inseriListAdj(gr->adj[vf].cab, vf, vi, p);
    
    gr->arestas++;
    return (true);
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

// ----------- PRIM ---------------------------
void agm_prim(GRAFO *gr, int orig, int *pai){
   // implemente o algoritmo de prim
   //h = vai ser o nosso grafo dos vertices
   //u = o vertice atual q estamos
   //peso
   //v = viznhos de u
   //s = novo grafo com os caminhos minimos da AGM
}

int main(){
    
    // crie o main para fazer a leitura do arquivo
    
    return 0;
}