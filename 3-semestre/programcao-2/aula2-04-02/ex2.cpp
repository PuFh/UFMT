#include <iostream>
#include <string>

//%0.2lf

int main() {

    std::string nome;
    int idade;
    float altura;

    std::printf("Digite o seu nome: ");
    std::getline(std::cin, nome);

    std::printf("Digite a sua idade: ");
    std::cin >> idade;

    std::printf("Digite a sua altura: ");
    std::cin >> altura;

    std::cout << "Seu nome eh " << nome << ", sua idade " << idade
              << " e altura : " << altura << std::endl;
}