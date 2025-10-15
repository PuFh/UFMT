#include <stdio.h>
#include<stdlib.h>

int main(){
    int num, antecessor, sucessor;

    printf("Digite o valor:");
    scanf("%d",&num);

    printf("O antecessor de %d é %d e o sucessor é %d",num,num-1,num+1);
    return 1;
}