#include <iostream>


int main(){
    int i,valor[3];

    for( i = 0; i < 3; i++){
        printf("Digite o valor %d: ",i);
        scanf("%d",&valor[i]);
    }
    for(i = 0; i < 3; i++){
        printf("Valor %d: %d\n",i+1,valor[i]);
    }
   
}