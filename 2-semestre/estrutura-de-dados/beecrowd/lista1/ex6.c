#include <stdio.h>
#include <stdlib.h>

int main(){
    int valor ,quantidade, i;
    int v[7]={100, 50, 20, 10, 5, 1};

    printf("VALOR: ");
    scanf("%d",&valor);
    i=0;
    while (i < 7){
        quantidade = valor/v[i];
        printf("%d nota(s) de R$ %d\n",quantidade, v[i]);
        valor = valor%v[i];
        i++;
    }
    
    
}