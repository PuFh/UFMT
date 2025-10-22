#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

void converte_para_title_case(std::string &texto) {
    std::vector<std::string> menores = {"a", "o", "e", "de", "da", "do", "das", "dos"};
    std::istringstream iss(texto);
    std::string palavra;
    std::vector<std::string> palavras;

    while (iss >> palavra) {
        for (auto &c : palavra) c = std::tolower(c);
        palavras.push_back(palavra);
    }

    for (std::size_t i = 0; i < palavras.size(); ++i) {
        bool primeira_ou_ultima = (i == 0 || i == palavras.size() - 1);
        bool eh_menor = std::find(menores.begin(), menores.end(), palavras[i]) != menores.end();

        if (!eh_menor || primeira_ou_ultima) {
            palavras[i][0] = std::toupper(palavras[i][0]);
        }
    }

    texto.clear();
    for (std::size_t i = 0; i < palavras.size(); ++i) {
        texto += palavras[i];
        if (i != palavras.size() - 1) texto += " ";
    }
}

int main() {
    std::string entrada;
    std::cout << "Digite um título: ";
    std::getline(std::cin, entrada);

    converte_para_title_case(entrada);
    std::cout << "Formato Title Case: " << entrada << "\n";
}