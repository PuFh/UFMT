#include <stdio.h>
#include <stdlib.h>

int main(){
    int v1, v2,i;

    printf("Digite os os limites de v1 e v2\n");
    scanf("%d",&v1);
    scanf("%d",&v2);
    
    i=v1+1;
    if(v2>v1){
        while(i<v2){
            if(i%6==0)
                printf("%d\n",i);
            i++;
        }
    }else{
        printf("valores incorretos");
    }

}