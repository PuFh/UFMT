#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    float altura[6],total, media, min, max;

    //leitura das alturas
    for(int i =0; i<6; i++){
        printf("A altura da pessoa %d: ",i+1);
        scanf("%f",&altura[i]);

    }

    //fazendo a média, irei usar um laço pra isso
    for(i=0; i<6; i++){
        total= total+altura[i];
        
    }
    media = total/6;
    //pegando a menor e a maior altura
    min = altura[0];
    max = altura[0];
    for(i=0; i<6; i++){
        if(altura[i] > max){
            max= altura[i];

        }
        if(altura[i] < min){
            min = altura[i];
        }
    }
    printf("A menor altura eh %.2f e a maior %.2f \n A media entrea as altura sera de %.2f.",min,max,media);
    printf("Fim algoritmo 11");
}