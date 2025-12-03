#ifndef CD_H
#define CD_H

#include "midia.h"

class CD : public Midia {
public:
    // Artista é o 'autor'
    CD(const std::string& t, const std::string& a) : Midia(t, a) {}

    void exibirInfo() const override {
        std::cout << "CD: " << titulo << " por " << autor << std::endl;
    }

    void reproduzir() const override {
        std::cout << "Tocando CD " << titulo << std::endl;
    }
};

#endif