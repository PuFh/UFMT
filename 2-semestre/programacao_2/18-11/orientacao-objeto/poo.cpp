#include <iostream>
//POO - paradigma orientação ao objeto

class Empregado
{

public:
    char nome[30];
    char endereco[50];
    float salario;

    void mostrarDados(){
        std::cout <<" "<<std::endl;
        std::cout <<"Nome:" <<nome<< std::endl;
        std::cout <<"Endereco: "<<endereco<< std::endl;
        std::cout <<"Salario:" <<salario<< std::endl;

    }
    void atualizar(){
        std::cout <<"Digite o novo Nome: "<<std::endl;
        std::cin.getline(nome, 30);

        std::cout <<"Digite o novo endereco: "<<std::endl;
        std::cin.getline(endereco, 50);

        std::cout <<"Digite5) o novo Salario: "<<std::endl;
        std::cin >>salario;
    }
};

int main(){
    Empregado fulano;

    fulano.atualizar();
    fulano.mostrarDados();

}
