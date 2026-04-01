#include <stdio.h>
#include <stdlib.h>

int main(){
    
    float v[10];
    float media =0.0;

    for(int i = 0; i < 10; i++){
        scanf("%f",&v[i]);

    }
    for(int i = 0; i < 10; i++){
        media = media + *(v+i);//equivalente a v[i]
    }
    media = media/10;
    printf("A media eh: %.2f\n",media);
    return 0;
}