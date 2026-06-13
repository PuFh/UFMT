#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define true 1
#define false 0
#define INT_INFINITO INT_MAX

#define START 1
//typedef int bool;
typedef int TIPOPESO;

typedef struct adjacencia{
    // registra o número do vertice
    int vertice;
    // registra o peso do vertices
    TIPOPESO peso;

    // proximo elemento da lista
    struct adjacencia *prox;
} ADJACENCIA;

typedef struct vertice
{
    /* Dados armazenados vao aqui */
    ADJACENCIA *cab;
} VERTICE;

typedef struct grafo
{
    // Guarda o número de vertives
    int vertices;
    // guarda o numero de arestas
    int arestas;
    // listas com os vértices adjacentes
    VERTICE *adj;
} GRAFO;

/* Criando um grafo */
GRAFO *criarGrafo(int v)
{

    // aloca memoria para uma strutura do tipo grafo
    GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO));

    // inicializa o quantidade de vertives
    g->vertices = v;
    // inicializa a quantidade arestas
    g->arestas = 0;
    // aloca memoria para uma vetor da quantidade de vertices
    g->adj = (VERTICE *)malloc(v * sizeof(VERTICE));
    int i;

    // inicializar as posições do vertives com NULL
    for (i = 0; i < v; i++)
        g->adj[i].cab = NULL;

    return g;
}

ADJACENCIA *criaAdj(int v, int peso)
{
    // Aloca memoria para um vertices adjacente
    ADJACENCIA *temp = (ADJACENCIA *)malloc(sizeof(ADJACENCIA));
    // define qual é o vertice
    temp->vertice = v;
    // atribui o peso
    temp->peso = peso;
    // define o proximo da lista como NULL
    temp->prox = NULL;
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
    }else{
        novo->prox = atual;
        ant->prox = novo;
    }

    return adj;
}

bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p)
{
    if (!gr)
        return (false);
    if ((vf < 0) || (vf >= gr->vertices))
        return (false);
    if ((vi < 0) || (vf >= gr->vertices))
        return (false);

    
    gr->adj[vi].cab = inseriListAdj(gr->adj[vi].cab, vi, vf, p);
    // gr->adj[vf].cab = inseriListAdj(gr->adj[vf].cab, vf, vi, p);
    gr->arestas++;
    return (true);
}

void imprime(GRAFO *gr)
{
    printf("Vertices: %d. Arestas: %d, \n", gr->vertices, gr->arestas);

    int i;
    for (i = START; i < gr->vertices; i++)
    {
        printf("v%d: ", i);
        ADJACENCIA *ad = gr->adj[i].cab;
        while (ad)
        {
            printf("v%d(%d) ", ad->vertice, ad->peso);
            ad = ad->prox;
        }

        printf("\n");
    }
}

//-------------relaxamento
int relax(VERTICE* u, VERTICE* v, ADJACENCIA* w){

    if(v->cab->peso > u->cab->peso + w->peso){
        v->cab->peso = u->cab->peso+w->peso;
        return v;
    }
    return  NULL;
}


// ----------- DIJKSTRA ---------------------------

int *dijkstra(GRAFO *g, int s, int *p){
    //implemente a função que realiza o algoritmo de dijkstra
    //implemente outras funções auxiliares necessárias
    for(int i = 0 ; i < g->vertices; i++){
        g->adj->cab->peso;
    }
}

///-------------------OU (EXCLUSIVO) ----------------------------

// ----------- BELLMAN FORD ---------------------------

int *bellman_ford(GRAFO *g, int s, int *p)
{
    //implemente a função que realiza o algoritmo de bellman_ford
    //implemente outras funções auxiliares necessárias
    for(int i = 1; i <g->vertices-1;i++){
         
    }
}

void caminho(GRAFO* g, int from ,int to, int *p){

    //implemente a função que imprime o caminho

}

int main(){
    char nomearquivo[] = "usa-road-d.CAL.gr";
    //char nomearquivo[] = "teste.gr";

    //     scanf("%s",nomearquivo);

    GRAFO *gr;

    FILE *arq;

    char entrada[50], c;

    int qtdnos, arcs, n1, n2, peso, i, j;
    // cria um vetor para armazenas o predecessor
    int *p;

    arq = fopen(nomearquivo, "r");
    if (arq == NULL)
    {
        puts("Deu ruim");
        return 0;
    }
    j = 0;
    int cont = 0;
    while (cont < 100 && fscanf(arq, "%c", &c) != EOF)
    {
        //  cont++;
        if (c == 'c')
        {

            fscanf(arq, "%[^\n]", entrada);
        }
        else if (c == 'p')
        {

            fscanf(arq, " sp %d %d", &qtdnos, &arcs);
            gr = criarGrafo(qtdnos+1);
            
            puts("#vertices criados#...");

            // Cria o vetor para armazenas os predecessores
            p = (int *)malloc(gr->vertices * sizeof(int));
        }
        else if (c == 'a')
        {
            fscanf(arq, " %d %d %d", &n1, &n2, &peso);

            printf("a-%d (%d,%d)[%d]\n", j++, n1, n2, peso);

            criaAresta(gr, n1, n2, peso);
            //
        }
    }

    puts("Arestas carregadas #...");
 
    imprime(gr);

    int find = 1;
    int no1,no2,no3;

    no1 = 4;
    no2 = 2;
    no3 = 5;
    
    /* 
    int *r = dijkstra(gr, find, p);
    int *r = bellman_ford(gr, find, p);
    */
    for (int i = START; i < gr->vertices; i++)
        printf("D(v%d -> v%d) = %d\n", find,i, gr[i]);
    

    caminho(gr,find,no1,p);
    caminho(gr,find,no2,p);
    caminho(gr,find,no3,p);

    return 0;
}