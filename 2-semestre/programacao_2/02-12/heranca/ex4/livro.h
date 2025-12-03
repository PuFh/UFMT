#ifndef LIVRO_H
#define LIVRO_H

#include "midia.h"

class Livro : public Midia {
public:
    Livro(const std::string& t, const std::string& a) : Midia(t, a) {}

    void exibirInfo() const override {
        std::cout << "Livro: " << titulo << " por " << autor << std::endl;
    }

    void reproduzir() const override {
        std::cout << "Abrindo o livro " << titulo << std::endl;
    }
};

#endif