// bicicleta.h
#ifndef BICICLETA_H
#define BICICLETA_H

#include "transporte.h"

class Bicicleta : public Transporte {
public:
    Bicicleta() : Transporte() {}

    void iniciar() const override {
        std::cout << "Bicicleta iniciando" << std::endl;
    }

    void parar() const override {
        std::cout << "Bicicleta parando" << std::endl;
    }
};

#endif