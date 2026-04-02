#include <iostream>
#include <string>


int main(){

    std::string nome;
    int idade;

    std::printf("Digite o seu nome: ");

    std::getline(std::cin,nome);

    std::printf("Digite a sua idade: ");
    std::cin >> idade;

    std::cout << "Seu nome eh "<< nome <<" e sua idade "<<idade<<std::endl;
}