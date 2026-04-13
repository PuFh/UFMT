#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* prox;
}no;

//prototipo
no* criaNo(int);
void imprimeLista(no*);
no* insereOrdem(no*, int);
no* exclui(no*, int);
no* alterar(no*, int, int);

//funcao principal
int main(){

    no* lista = criaNo(0);
    
    
    
    int opcao = 0;
    
    while (opcao != 5){
        
        printf("-------------------\n");
        printf("| LISTA ORDENADA  |\n");
        printf("-------------------\n");
        printf("1 -> Adicionar\n");
        printf("2 -> imprimir\n");
        printf("3 -> Excluir\n");
        printf("4 -> Alterar\n");
        printf("5 -> Sair\n");
        printf("\n-->");
        scanf("%d",&opcao);
        
        switch (opcao){
        case 1:
            printf("Digite o valor no qual voce deseja adicionar: ");
            int valor;
            scanf("%d",&valor);
    
            lista = insereOrdem(lista, valor);
            
            break;
        case 2:
    
            imprimeLista(lista);
            break;

        case 3:
            printf("Digite o valor no qual voce deseja remover: ");
            int remove;
            scanf("%d",&remove);
    
            lista = exclui(lista, remove);
            break;
        
        case 4:
            printf("Digite o valor no qual voce deseja substituir:");
            int antigo;
            scanf("%d",&antigo);

            printf("Qual voce ira ficar no lugar?");
            int novo;
            scanf("%d", &novo);
            

            lista = alterar(lista, antigo, novo);
            

            break;

        case 5:
    
            return 1;
            break;
        
        
        default:
            printf("Opcao Invalida\n");
            break;
        }
       
    }

}

//funcao cria um no
no* criaNo(int v){

    no* novo = (no*)malloc(sizeof(no));

    if(novo == NULL){
        printf("Error\n");
        return 0;
    }

    novo->valor = v;
    novo->prox = NULL;
    return novo;
}

//funcao imprime
void imprimeLista(no* li){
    if(li == NULL){
        printf(" NULL\nFim da Lista\n");
        return;
    }

    printf(" %d-->",li->valor);
    imprimeLista(li->prox);
}

//funcao insere ordem
no* insereOrdem(no* li, int v){
    no* novo = criaNo(v);

    // caso 1: v menor que valor inicial da lista
    if(li == NULL || li->valor > v){
        novo->valor = v;
        novo->prox = li;
        li = novo;

        return li;
    }

    //caso 2: encontrar a posicao de li
    no* prox = li;
    no* ant = li;

    while(prox != NULL && prox->valor < v){
        //avanca uma posicao e o ant fica uma posicao atras de prox
        ant = prox;
        prox = prox->prox;
    }

    ant->prox = novo;
    novo->prox = prox;

    return li;
}

//funcao remove valor
no* exclui(no* li, int excluir){

    //caso o valor seja o primeiro
    if(li->valor == excluir){
    no* temp = li;
    li = li->prox;
    free(temp);
    return li;
    }


    no* prox = li;
    no* ant = li;
    //faremos um laco para percorrer a lista se for diferente de nula ou se o valor que queremos excluir for diferente do valor da posicao que a lista esta
    while(prox != NULL){
        if(prox->valor == excluir){
            ant->prox = prox->prox;//isso faz com que pulemos o bloco que queremos excluir(que é somento o prox)
            free(prox);

            return li;
        }
        else{
            ant= prox;
            prox = prox->prox;
        }

    }
    printf("Valor nao existe na sua lista!\n");
    return li;
}


//funcao alterar
no* alterar(no* li, int vAntigo, int vNovo){
    
    //caso 1: valor inicial da lista for oq iremos substituir
    if(li->valor == vAntigo){
        //verificar se esta ordenado
        li = exclui(li, vAntigo);
        li = insereOrdem(li, vNovo);

        return li;
    }

    //caso 2: percorrer a lista ate encontrar o valor para sub
    no* prox = li;
    no* ant = li;

    while (prox != NULL && prox->valor != vAntigo){
        //avancamos uma posicao e o ant fica na posicao antiga para n perdermos a referencia
        ant = prox;
        prox = prox->prox;
    }
    
    //se chegamos ate aqui temos 2 casos, 1 eh se a prox = null, entao n encontramos o valor, o 2 eh se encontramos
    if(prox == NULL){
        printf("Valor nao existe\n");
        return li;
    }else{
        //o valor existe, entao prox->valor é = a vantigo

        //verificar se esta ordenado
        li = exclui(li, prox->valor);
        li = insereOrdem(li, vNovo);

        return li;
    }

    
}
