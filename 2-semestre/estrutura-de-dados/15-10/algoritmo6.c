#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    i=1;

    //1 variacao
    while(i<=100){
        printf(" tipo 1: contagem %d\n",i);
        i++;
    }
    //segunda variacao
    for(int t=1;t<=100;t++){
        printf("2 tipo: Contagem %d\n",t);
    }
    //terceira variacao
    int m;
    m=1;
    do{
        printf("3 tipo: Contagem %d\n",m);
        m++;
    }while (m<=100);
    

    return 1;
}