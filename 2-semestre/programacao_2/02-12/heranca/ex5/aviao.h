// aviao.h
#ifndef AVIAO_H
#define AVIAO_H

#include "transporte.h"

class Aviao : public Transporte {
public:
    Aviao() : Transporte() {}

    void iniciar() const override {
        std::cout << "Aviao decolando" << std::endl;
    }

    void parar() const override {
        std::cout << "Aviao pousando" << std::endl;
    }
};

#endif