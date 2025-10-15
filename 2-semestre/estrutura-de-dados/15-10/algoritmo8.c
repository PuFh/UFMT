#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    float num,somador, media;

    somador=0;
    num =0;
    i=1;
    while(num >= 0){
        printf("Digite um valor na media: \n");
        scanf("%f",&num);
        somador +=num;
        i++;
    }
    media = somador/i;

    printf("A média entre os valores é %f",media);
}