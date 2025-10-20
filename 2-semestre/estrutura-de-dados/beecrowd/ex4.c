#include <stdio.h>
#include <stdlib.h>

int main(){
    int number, h_work, v_work, salario;
    printf("Digite o numero do funcionario: ");
    scanf("%d",&number);
    printf("Digite as horas trabalhadas: ");
    scanf("%d",&h_work);
    printf("Digite o numero do funcionario: ");
    scanf("%d",&v_work);

    salario = h_work*v_work;

    printf("NUMBER = %d\n",number);
    printf("SALARY = %.2d",salario);
    return 0;
}