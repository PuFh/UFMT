#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,b,c,d,diferenca;
    diferenca=0;

    printf("Digite o valor A\n");
    scanf("%d",&a);
    printf("Digite o valor B\n");
    scanf("%d",&b);
    printf("Digite o valor C\n");
    scanf("%d",&c);
    printf("Digite o valor D\n");
    scanf("%d",&d);

    diferenca = (a*b)-(c*d);

    printf("DIFERENCA = %d",diferenca);

    return 0;
}