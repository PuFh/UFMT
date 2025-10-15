#include <stdio.h>
#include <stdlib.h>

int main(){
    int num1,num2,adicao;

    printf("Digite os valores: \n");
    scanf("%d",&num1);
    scanf("%d",&num2);

    adicao=num1-num2;

    if (adicao>10){
        printf("%d",adicao);
    }else{
        printf("O valor é inferior a 10");
    }

    return 1;
}