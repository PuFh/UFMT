#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,b,n,resultado;

    printf("Digite um valor da base: \n");
    scanf("%d",&b);
    printf("Digite um valor da potencia: \n");
    scanf("%d",&n);

    i=1;
    resultado =1;
    while(i<=n){
        if(n>1 && b>=2){
            resultado*=b;
            i++;
        }else{
            printf("O n tem que ser maior que 1 e o b maior ou igual a 2");
        }
    }
    printf("O valor é %d",resultado);
    

}