#include <stdlib.h>
#include <stdio.h>

const int linha = 11;
const int coluna = 11;

int main(){
    char letra;
    int i, t, m;
    float matriz[linha][coluna];
    float valor, media;


    //soma ou media
    scanf(" %c",&letra);
    //Leitura a matriz
    for(i = 0; i < linha; i++){
        for(t = 0; t < coluna; t++){
            scanf("%f",&matriz[i][t]);
        }

    }
    // for(i = 0; i < linha; i++){
    //     for(t = 0; t < coluna; t++){
            
    //         printf("Valor a matriz[%d][%d] = %.2f\n",i,t,matriz[i][t]);
    //     }

    // }
    m = 0;
    valor = 0.0;
    media = 0.0;
    //fazeno a soma

    for(i = 0; i < linha; i++){
        for(t = 0; t < coluna; t++){
            if(t > i){
                valor += matriz[i][t];
                m++;
            }
        }
    }

    if(letra == 'S'){
        printf("%.1f",valor);
    }else if (letra == 'M') {
        media = valor / m;
        printf("%.1f\n", media);
    } else {
        printf("Valor inválido\n");
    }
    return 0 ;
}