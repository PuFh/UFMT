#ifndef DVD_H
#define DVD_H

#include "midia.h"

class DVD : public Midia {
public:
    // Diretor é o 'autor'
    DVD(const std::string& t, const std::string& a) : Midia(t, a) {}

    void exibirInfo() const override {
        std::cout << "DVD: " << titulo << " dirigido por " << autor << std::endl;
    }

    void reproduzir() const override {
        std::cout << "Reproduzindo DVD " << titulo << std::endl;
    }
};

#endif