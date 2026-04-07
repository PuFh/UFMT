#include <iostream>
#include <string>


int main(){
    std::string nome;
    float salario;

    printf("Nome: ");
    std::getline(std::cin, nome);

    printf("Salario: ");
    scanf("%f",&salario);

    printf("--------------\n");
    printf("Nome: %s\nSalario %.2f\n",nome.c_str(),salario);
    printf("--------------\n");

    
   
}