#include <stdio.h>
#include <string.h>

#define MAX_STRING 100
#define CAPACIDADE 50
#define MAX_PRODUTOS 20

struct Produto{
    char nome[MAX_STRING];
    int codigo;
    float preco;
};

int main(){
    //produtos esta alocado no struct Produto
    struct Produto produtos[CAPACIDADE];
    int i= 0,t = 0, opcao, codigo_verificao;

    while(i < CAPACIDADE){
        printf("[1]Cadastrar \n");
        printf("[2]Imprimir \n");
        printf("[3]SAIR \n");
        scanf("%d",&opcao);

        if(opcao == 1){
            
            printf("Codigo do Produto: ");
            //scanf("%d",&produtos[i].codigo);
            scanf("%d",&codigo_verificao);
            //Faz a verificação para ver se já existe este código
            for(t=0; t < i; t++){
                if(codigo_verificao == produtos[t].codigo){
                    printf("Este codigo já foi utilizado!\n");
                    break;
                }
                // else{
                //     produtos[t].codigo = codigo_verificao;

                // }

            }
            //como na linha anterior o break só sai do for, nos precisamos voltar ao
            //inicio do while, e para isso usamos esta verificação
            //fiz sem IA, sou mt foda
            if(codigo_verificao != produtos[t].codigo){
                produtos[i].codigo = codigo_verificao;
    
                printf("Nome do Produto: ");
                scanf("%s",produtos[i].nome);
                printf("Digite o valor do Produto:");
                scanf("%f",&produtos[i].preco);
                i++;
            }
        }
        else if (opcao == 2){
            t = 0;
            while(t < i){
                printf("--------------------\n");
                printf("%s\n",produtos[t].nome);
                printf("%d\n",produtos[t].codigo);
                printf("%.2f\n",produtos[t].preco);
                t++;
            }
        }
        else if (opcao == 3){
            i = 50;
        } 
        else{
            printf("Opção indisponivel");
        }
        
        
        
    }
    printf("------------\n");
    printf("Fim do Programa!\n");



    return 0;
}