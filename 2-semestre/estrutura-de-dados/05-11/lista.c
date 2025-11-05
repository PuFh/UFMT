//inclusao do cabecalho
#include "lista.h"

//preocedimento que imprime a lista
void imprimeLista(tipo_lista lst){
    int i;

    printf("LISTA: [");
    for(i = 0; i < lst.contador; i++)
        printf("%d ",lst.lista[i]);
    printf("] \nQuantidade de elementos = %d\n",lst.contador);
}
//funcao que insere valor no inicio da lista
int insereInicioLista(tipo_lista *lst, int valor){ 
    int i;

    if(lst->contador < N){ //lst-->contado é a mesma coisa que (*lst).contador = esta indo no endereço do contador e chamando ele
        for( i = lst->contador; i > 0; i--){
            lst->lista[i] = lst->lista[i-1];
        }
        lst->lista[0] = valor;
        lst->contador++;
        
    }

}

