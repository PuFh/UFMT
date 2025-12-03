#ifndef CARRO_H
#define CARRO_H

#include "transporte.h"

class Carro : public Transporte {
public:
    Carro() : Transporte() {}

    void iniciar() const override {
        std::cout << "Carro iniciando" << std::endl;
    }

    void parar() const override {
        std::cout << "Carro parando" << std::endl;
    }
};

#endif