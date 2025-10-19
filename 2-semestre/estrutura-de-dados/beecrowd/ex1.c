#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,b,x;

    printf("Digite o valor de A \n");
    scanf("%d",&a);
    printf("Digite o valor de B \n");
    scanf("%d",&b);

    x = a+b;

    printf("A soma entre %d e %d é %d",a,b,x);
    return 0;
}