#include <iostream>
#include <string>

std::string::size_type busca_vogal_e_conta(
    const std::string &s,
    std::string::size_type &total_vogais
) {
    const std::string vogais = "AEIOUaeiou";
    total_vogais = 0;
    std::string::size_type primeira = s.size();

    for (std::string::size_type i = 0; i < s.size(); ++i) {
        if (vogais.find(s[i]) != std::string::npos) {
            ++total_vogais;
            if (primeira == s.size()) primeira = i;
        }
    }

    return primeira;
}

int main() {
    std::string texto;
    std::cout << "Digite um texto: ";
    std::getline(std::cin, texto);

    std::string::size_type total = 0;
    std::string::size_type indice = busca_vogal_e_conta(texto, total);

    if (indice == texto.size()) {
        std::cout << "Nenhuma vogal encontrada.\n";
    } else {
        std::cout << "Primeira vogal no índice: " << indice << "\n";
    }

    std::cout << "Total de vogais: " << total << "\n";
}