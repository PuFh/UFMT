#include <iostream>
#include <string>
#include <cctype>

bool valida_senha(const std::string &senha) {
    if (senha.size() < 8) return false;

    bool maiuscula = false, minuscula = false, digito = false, simbolo = false;

    for (char c : senha) {
        if (std::isupper(static_cast<unsigned char>(c))) maiuscula = true;
        else if (std::islower(static_cast<unsigned char>(c))) minuscula = true;
        else if (std::isdigit(static_cast<unsigned char>(c))) digito = true;
        else simbolo = true;
    }

    return maiuscula && minuscula && digito && simbolo;
}

int main() {
    std::string senha;
    std::cout << "Digite sua senha: ";
    std::getline(std::cin, senha);

    if (valida_senha(senha)) {
        std::cout << "Senha válida!\n";
    } else {
        std::cout << "Senha inválida. Ela deve conter:\n";
        std::cout << "- Mínimo de 8 caracteres\n";
        std::cout << "- Letra maiúscula e minúscula\n";
        std::cout << "- Pelo menos 1 número\n";
        std::cout << "- Pelo menos 1 símbolo\n";
    }
}