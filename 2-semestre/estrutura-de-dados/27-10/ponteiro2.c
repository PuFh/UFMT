#include <stdio.h>
#include <stdlib.h>

int main(){
    int x;
    int *ponteiro;
    int *pt2;

    printf("Informe o valor de x: ");
    scanf("%d",&x);

    ponteiro = &x;

    printf("Endereço de &x: %p\n", &x);
    printf("Valor (endereço) armazenado e ponteiro = %p\n",ponteiro);
    printf("Valor alcancado por *ponteiro = %d",*ponteiro);
    printf("Endereço do &ponteiro = %p",&ponteiro);

    pt2 = (int*) malloc(sizeof(int));
    *pt2 = 10;

    printf("\nEndereco ARMAZENADO em pt2 = %p\n",pt2);
    printf("Valor amazendo em *pt2 = %d\n",*pt2);
    printf("Endereço do ponteiro &pt2 = %p\n",&pt2);

    *ponteiro = 50;
    printf("Valor ARMAZENADO em *pt1 = %d\n",*ponteiro);
    printf("Valor ARMAZENADO em *pt2 = %d\n",*pt2);



    return 0;
}