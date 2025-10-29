#include <stdio.h>

int somavalores(int v1, int v2);

int somavalores(int v1, int v2){
    int resultado;
    resultado = v1+v2;
    return resultado;
}
int main(){
    int x, y, total;

    printf("Digite o valor de x e y: ");
    scanf("%d",&x);
    scanf("%d", &y);

    total = somavalores(x,y);

    printf("Total eh: %d\n",total);

    return 0;
}