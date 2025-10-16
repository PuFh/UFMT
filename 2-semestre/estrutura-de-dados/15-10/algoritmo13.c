#include <stdio.h>
#include <stdlib.h>

int main(void){
    int op, num1, num2,soma,mult;

    printf("MAQUINA ESPERTA\n");
    printf("\nOpcao(1) - Soma de dois numeros; \nOpcao(2) - Multiplicacao de dois numeros; \nOpcao(3) - Sair \n");
    printf("\nDigite a sua opcao: \n");
    scanf("%d",&op);


    switch (op){
        case 1:
            printf("Digite 2 valores: \n");
            scanf("%d",&num1);
            scanf("%d",&num2);
            soma = num1+num2;

            printf("A SOMA ENTRE ELES EH: %d\n",soma);
            break;
        case 2:
            printf("Digite 2 valores: \n");
            scanf("%d",&num1);
            scanf("%d",&num2);
            mult = num1*num2;

            printf("A MULTIPLICACAO ENTRE ELES EH: %d\n",mult);
            break;
        case 3:
            printf("Voce saiu!");
            break;
        default:
            printf("Valor invalido");
            
    }

    return EXIT_SUCCESS; 
}