#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOPESO;
int inicio,fim;
typedef struct adjacencia{
int vertice;
TIPOPESO peso;
struct adjacencia *prox;
} ADJACENCIA;
typedef struct vertice{
/* Dados armazenados vao aqui */
ADJACENCIA *cab;
} VERTICE;
typedef struct grafo {
int vertices;
int arestas;
VERTICE *adj;
} GRAFO;
/*
* criarGrafo: aloca e inicializa um novo grafo com um numero fixo de vertices,
* sem nenhuma aresta.
*
* Entrada:
* v - numero de vertices do grafo
*
* Saida:
* ponteiro para o GRAFO alocado, com gr->vertices = v, gr->arestas = 0
* e todas as listas de adjacencia vazias (cab = NULL)
*/
GRAFO *criarGrafo(int v){
GRAFO *gr =(GRAFO *)malloc(sizeof(GRAFO));
gr->vertices = v;
gr->arestas = 0;
gr->adj = (VERTICE *)malloc(v * sizeof(VERTICE));
int i;
for(i = 0; i < v; i++){
gr->adj[i].cab = NULL;
}
return gr;
}
/*
* criaAdj: cria e inicializa um novo no de adjacencia (aresta) para ser
* inserido em uma lista de adjacencia.
*
* Entrada:
* v - indice do vertice de destino apontado por esta adjacencia
* peso - peso associado a esta adjacencia
*
* Saida:
* ponteiro para o novo no ADJACENCIA alocado, com campo prox iniciado
* como NULL (o no ainda nao esta ligado a nenhuma lista)
*/
ADJACENCIA *criaAdj(int v,int peso){
ADJACENCIA *temp= (ADJACENCIA *)malloc(sizeof(ADJACENCIA));
temp->vertice = v;
temp-> peso = peso;
temp->prox = NULL;
return temp;
}
/*
* criaAresta: insere uma aresta ponderada entre dois vertices de um grafo nao direcionado.
*
* Entrada:
* gr - ponteiro para o grafo onde a aresta sera inserida
* vi - indice do vertice de origem (0 a gr->vertices-1)
* vf - indice do vertice de destino (0 a gr->vertices-1)
* p - peso da aresta
*
* Saida:
* true - aresta criada com sucesso
* false - gr eh NULL ou algum dos indices (vi, vf) esta fora do intervalo valido
*
* Efeito: como o grafo eh nao direcionado, adiciona vf na lista de adjacencia
* de vi e vi na lista de adjacencia de vf (cada insercao no inicio da lista),
* e incrementa o contador de arestas do grafo.
*/
bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p){
if(!gr) return false;
if((vf < 0) || (vf >= gr->vertices)) return false;
if((vi < 0) || (vi >= gr->vertices)) return false;
ADJACENCIA *novo1 = criaAdj(vf,p);
novo1->prox = gr->adj[vi].cab;
gr->adj[vi].cab = novo1;
ADJACENCIA *novo2 = criaAdj(vi,p);
novo2->prox = gr->adj[vf].cab;
gr->adj[vf].cab = novo2;
gr->arestas++;
return true;
}
void imprime(GRAFO *gr){
printf("Vertices: %d. Arestas: %d, \n", gr->vertices,gr->arestas);
int i;
for(i=0;i<gr->vertices; i++){
printf("v%d: ",i);
ADJACENCIA *ad = gr->adj[i].cab;
while(ad){
printf("u%d(%d) ", ad->vertice,ad->peso);
ad = ad->prox;
}
printf("\n");
}
}
//vou começar a implememntação aqui, eu estudei e fiz ela separado em outro arquivo como
teste então agora vou escreve-la aqui
int *colorirDSATUR(GRAFO *gr){
int n = gr->vertices;
int *cor = (int *)malloc(n * sizeof(int));
int *grau = (int *)malloc(n * sizeof(int));
int *dsat = (int *)malloc(n * sizeof(int));
for (int i = 0; i < n; i++){
cor[i] = 0;
dsat[i] = 0;
int g = 0;
ADJACENCIA *adj = gr->adj[i].cab;
while (adj != NULL){
g++;
adj = adj->prox;
}
grau[i] = g;
}
int maxGrau = -1;
int vInicial = -1;
for (int i = 0; i < n; i++){
if(grau[i] > maxGrau){
maxGrau = grau[i];
vInicial = i;
}
}
if (vInicial != -1){
cor[vInicial] = 1;
}
for(int passo = 1; passo < n;passo++){
for (int i = 0; i< n; i++){
if(cor[i] == 0){
int *coresVizinhos = (int *)calloc(n + 1, sizeof(int));
int sat = 0;
ADJACENCIA *adj = gr->adj[i].cab;
while(adj != NULL){
int viz = adj->vertice;
if (cor[viz] != 0 && coresVizinhos[cor[viz]] == 0){
coresVizinhos[cor[viz]] = 1;
sat++;
}
adj = adj->prox;
}
dsat[i] = sat;
free(coresVizinhos);
}
}
int maxDsat = -1;
int maxGrauNaoColorido = -1;
int vEscolhido = -1;
for(int i = 0;i < n; i++ ){
if (cor[i] == 0){
int grauSub = 0;
ADJACENCIA *adj = gr->adj[i].cab;
while (adj != NULL){
if (cor[adj->vertice] == 0){
grauSub++;
}
adj = adj->prox;
}
if(dsat[i] > maxDsat){
maxDsat = dsat[i];
maxGrauNaoColorido = grauSub;
vEscolhido = i;
}else if (dsat[i] == maxDsat){
if (grauSub > maxGrauNaoColorido){
maxGrauNaoColorido = grauSub;
vEscolhido = i;
}
}
}
}
if (vEscolhido != -1){
int *corDisp = (int *)malloc((n + 2) * sizeof(int));
for (int k = 0;k <= n + 1;k++){
corDisp[k] = 1;
}
ADJACENCIA *adj = gr->adj[vEscolhido].cab;
while(adj != NULL){
int viz = adj->vertice;
if(cor[viz] != 0){
corDisp[cor[viz]] = 0;
}
adj = adj->prox;
}
int menorCor = 1;
while(corDisp[menorCor] == 0){
menorCor++;
}
cor[vEscolhido] = menorCor;
free(corDisp);
}
}
free(grau);
free(dsat);
return cor;
}
int main(){
GRAFO *gr = criarGrafo(12);
criaAresta(gr,0,1,1);
criaAresta(gr,0,2,1);
criaAresta(gr,1,3,1);
criaAresta(gr,2,3,1);
criaAresta(gr,2,5,1);
criaAresta(gr,2,4,1);
criaAresta(gr,4,5,1);
criaAresta(gr,5,6,1);
criaAresta(gr,3,7,1);
criaAresta(gr,3,8,1);
criaAresta(gr,3,9,1);
criaAresta(gr,8,9,1);
criaAresta(gr,7,8,1);
criaAresta(gr,7,9,1);
criaAresta(gr,10,11,1);
imprime(gr);
int *cores = colorirDSATUR(gr);
printf("\nResultado da colocacao\n");
for (int i = 0; i < gr->vertices; i++){
printf("vertice %d -> Cor %d\n", i, cores[i]);
}
free(cores);
return 0;
}