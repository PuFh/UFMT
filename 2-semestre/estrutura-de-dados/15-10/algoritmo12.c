#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i, n;
    float h;

    printf("Digite o tamanho da serie: ");
    scanf("%d",&n);

    i=1;
    h=0;
    if (n > 0 ){
        while(i < n){
            h = h + (1.0/i);
            i++;
        }
        
    }else{
        printf("Digite um valor positivo");
    }
    printf("A soma da serie eh: %.4f\n",h);

    printf("FIm do programa 13");
    return 0 ;
}
