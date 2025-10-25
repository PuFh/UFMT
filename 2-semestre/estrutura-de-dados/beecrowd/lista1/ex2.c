#include <stdio.h>
#include <stdlib.h>

int main(){
    double n1,n2,media;
    media =0.0;

    printf("Digite o valor da sua primeira e segunda nota. \n");
    scanf("%lf",&n1);
    scanf("%lf",&n2);
    media= (n1*0.35)+(n2*0.75);
    
    if (n1 > 10 || n2 > 10){
        printf("Digite uma nota menor ou igual a 10");
    }else{
        printf("MEDIA = %.2lf",media);
    }

    return 0;
}