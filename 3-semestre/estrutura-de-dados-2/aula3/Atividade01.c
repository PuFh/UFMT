#include <stdio.h>
#include <stdlib.h>

typedef struct tempNo {
    float valor;
    int coluna;
    struct tempNo* prox;
}NO;

typedef NO* PONT;

typedef struct {
    PONT* A;
    int linhas;
    int colunas;
} MATRIZ;

MATRIZ *inicializarMatriz(int lin, int col){
    int i;
    
    MATRIZ *novo;
    
    novo = (MATRIZ *) malloc (sizeof(MATRIZ));
    
    novo->A = (PONT *) malloc(lin*sizeof(PONT));
    novo->linhas = lin;
    novo->colunas = col;
    for(i=0;i<lin;i++)
        novo->A[i] = NULL;
    
    return novo;
}

void imprimeMatriz(MATRIZ* m){
    for(int l=0; l < m->linhas; l++){
        if(m->A[l] != NULL){
            PONT c = m->A[l];
            while( c != NULL){
                printf("  [%f|(%d,%d)]",c->valor,l,c->coluna);
                c = c->prox;
            }
            printf("\n");
        }
    }
}

// função que insere um valor na matriz
int insereMatriz(MATRIZ* m, int lin, int col, float val){
   // implemente aqui seu código
    
   //se a linha e coluna existe
    if(lin > m->linhas && col > m->colunas){
        printf("Posicao invalida\n");
        return 0;
    }
    //se o valor é != 0
    if(val == 0){
        return 0;
    }
    //implementacao do valor
    //cria um no para adicionar
    PONT novo;
    novo = (PONT)malloc(sizeof(NO));

    novo->valor = val;
    novo->coluna = col;
    novo->prox = NULL;//por enquanto
    //percorrer a linha
    for(int i = 0; i != lin; i++){
        //percorre ate o i ser igual a lin
        m->A[i] = m->A[i+1];
    }
    //aqui estamos na posicao exata para percorrermor as colunas
    PONT ax = m->A[lin];
    PONT ant = ax;
    while(ax->coluna != col){
        ant = ax;//uma posicao atras
        ax = ax->prox;
        if(ax->coluna == col){
            ant->prox = ax;
            m->A[lin] = novo;//essa posicao receba os valores, se ja existia sobrescreve
            return 0;
        }
    }
    return 1;//nao foi alocado
    //ultimo valor
    
}


// função que retorna o valor
float ValorMatriz(MATRIZ* m, int lin, int col){
   // implemente aqui seu código 
}

int excluirMatriz(MATRIZ *m, int lin, int col)
{
    // implemente aqui seu código
}


// A função main não deve ser alterada quando for enviar
int main(){
    
    MATRIZ *m;
    
    m = inicializarMatriz(4,4);

    insereMatriz(m,2,3,2.5);//a matriz q vamos add, lin,col,val
   


    
    imprimeMatriz(m);
    
   


    return 0;
}