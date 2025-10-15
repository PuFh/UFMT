#include <stdio.h>
#include <stdlib.h>

int main(){
    int num1, num2;

    printf("Digite os valores dos números: \n");
    scanf("%d",&num1);
    scanf("%d",&num2);

    printf("A soma entre %d e %d é %d e o produto %d"
        ,num1,num2,num1+num2,num1*num2);


    return 1;
}