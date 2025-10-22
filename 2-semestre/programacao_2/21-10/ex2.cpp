#include <iostream>
#include <string>

int main() {
    const std::string::size_type LIMITE = 80;
    std::string linha;
    std::string primeira_longa;
    std::string::size_type contador = 0;

    std::cout << "Digite linhas (ou 'SAIR' para encerrar):\n";

    while (true) {
        std::getline(std::cin, linha);
        if (linha == "SAIR") break;

        if (linha.size() > LIMITE) {
            ++contador;
            if (primeira_longa.empty()) {
                primeira_longa = linha;
            }
        }
    }

    std::cout << "Total de linhas longas: " << contador << "\n";
    if (!primeira_longa.empty()) {
        std::cout << "Primeira linha longa: " << primeira_longa << "\n";
    }
}