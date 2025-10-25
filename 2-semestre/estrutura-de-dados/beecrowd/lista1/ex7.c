#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float a, b, c, x1, x2;

    //POW(BASE, EXPOENTE)
    //sqrt(x), paara raiz quadrada
    printf("Digite os valores de a,b e c\n");
    scanf("%f",&a);
    scanf("%f",&b);
    scanf("%f",&c);

    if(a==0){
        printf("Impossivel calcular");
        return 0;
    }
    float delta;

    delta = pow(b,2) -4*a*c;
    if(delta<0){
        printf("Impossivel calcular");
        return 0;
    }
    x1 = (-b + sqrt(delta))/(2*a);
    x2 = (-b - sqrt(delta))/(2*a);

    printf("O valor de x1 eh %.4f, e de x2 %.4f",x1,x2);
    
    return 0;
}