#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define true 1
#define false 0
#define INT_INFITO INT_MAX/* a variavel do jeito q tava conflitando com um constante de uma das biblioteca, pois o a varivel com o nome INT-MAX ja existia
entao pra resolver o problema e manter oq se espera, q é um valor infinito apra todos os vertice, eu troquei o nome para INT_INFINITO e fiz ela receber o maior valor possivel
que seria o INT_MAX, Ai n conflita com nada
*/

//typedef int bool; tava dando erro na compilacao
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
   //v = viznhos de u
   //s = novo grafo com os caminhos minimos da AGM
   // ------ Irei me basear no pseudo-codigo dos slides
   //peso -> tem que receber o vertices
   // visitado -> se foi ou n visitado
    TIPOPESO* peso = (TIPOPESO*)malloc(gr->vertices*sizeof(TIPOPESO));
    bool* visitado = (bool*)malloc(gr->vertices * sizeof(bool));// 0 se n foi e 1 se foi
    //-----INICIALIZACAO
    //iremos percorrer todos os vertices e iremos fazer eles serem infinito, aqui vamos demorar muito tempo
    for(int i = 0; i < gr->vertices;i++){
        peso[i] = INT_INFITO;
        visitado[i] = 0;
        pai[i] = -1;
    }
    peso[orig] = 0;/*
    seria o primeiro vertice que vamos fazer, e como ele é o primeiro ele tem peso 0
    foi que nem o grafo que fizemos em sala de aula, esse seria o nosso 'A', e como ele ' é o prmeiro ele tem
    pai NULL e peso 0, no caso n precisamo fazer ele -1 pq ja fizemos isso no laco em cima
    */
    /*
    controi heap minimo A com V(G) (com base em p), isso ta no slide
    */
   int contador = gr->vertices;
   while(contador >= 1){
    //percorrer todos os vertices vizinhos
    int u = -1;
    int min = INT_INFITO;
    for(int i=0; i < gr->vertices; i++){
        //se foi visitado
        if(visitado[i] == 0 && peso[i] < min){
            min = peso[i];
            u = i;
        }
    }
    visitado[u] = 1;
    //percorrer os vizinhos de u
    ADJACENCIA* ad = gr->adj[u].cab;

    while (ad != NULL){
        int v = ad->vertice;
        int w = ad->peso;

        //condicao caso tenha sido visitado
        if(visitado[v] == 0 && peso[v] > w){
            peso[v] = w;
            pai[v] = u;
        }
        ad = ad->prox;
    }
    contador--;
   }
}

int main(){
    FILE *f = NULL;

    int opcao;
    printf("1 - NY\n");
    printf("2 - CAL\n");
    printf("Digite: ");
    scanf("%d", &opcao);


    if(opcao ==1)
        f = fopen("USA-road-d.NY.gr/USA-road-d.NY.gr", "r");
    else if(opcao ==2)
        f = fopen("USA-road-d.CAL.gr/USA-road-d.CAL.gr", "r");
    else{
        printf("Opcao invalida\n");
        return 1;
    }
    //caso esteja vazia
    if( f == NULL){
            printf("Erro ao abrir arquivo");
            return 1;
    }
    //aqui iremos criar a nossa arvore e gerar o tempo que demoramos
    char linha[256];
    GRAFO* gr = NULL;
    int v,a,vi,vf,peso;

    while (fgets(linha, 256, f) != NULL){
        if(linha[0] == 'c')
            continue;
        if(linha[0] == 'p'){
            sscanf(linha, "p sp %d %d", &v, &a);
            gr = criarGrafo(v);
        }
        if(linha[0] == 'a'){
            sscanf(linha, "a %d %d %d", &vi, &vf , &peso);
            criaAresta(gr, vi-1, vf-1, peso);
        }
    }
    fclose(f);
    
    int *pai = (int*)malloc(gr->vertices *sizeof(int));

    clock_t inicio = clock();
    agm_prim(gr, 0, pai);
    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    long long custo = 0;
    for(int i = 0; i < gr->vertices; i++){
        if(pai[i] != -1){
            ADJACENCIA *ad = gr->adj[pai[i]].cab;
            while (ad != NULL){
                if(ad->vertice == i){
                    custo += ad->peso;
                    break;
                }
                ad = ad->prox;
            }
        }
    }
    FILE *saida = fopen("resultado.txt","w");
    fprintf(saida, "Custo total: %lld\n", custo);
    fprintf(saida, "Tempo: %f segundos\n",tempo);
    fclose(saida);


    return 0;
}