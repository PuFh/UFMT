#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;

    printf("Digite um valor: \n");
    scanf("%d",&num);

    if(num%3==0){
        printf("%d é multiplo de 3");
    }else{
        printf("%d não é multiplo de 3!");
    }

    return 1;
}