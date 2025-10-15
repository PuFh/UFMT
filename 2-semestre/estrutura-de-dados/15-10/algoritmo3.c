#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;

    printf("Digite o valor do número: \n");
    scanf("%d",&num);

    if(num>20){
        printf("%d",num);
    }
    else{
        printf("Número inferior a 20\n");
    }


    return 1;
}