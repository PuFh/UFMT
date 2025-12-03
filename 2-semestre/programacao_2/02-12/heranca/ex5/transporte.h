#ifndef TRANSPORTE_H
#define TRANSPORTE_H

#include <iostream>
#include <string>

class Transporte {
public:
    // Construtor padrão (pode ser vazio, pois não há atributos de inicialização)
    Transporte() {}

    // Metodos Virtuais Puros (ou implementacao padrao)
    virtual void iniciar() const {
        std::cout << "Transporte iniciando" << std::endl;
    }
    
    virtual void parar() const {
        std::cout << "Transporte parando" << std::endl;
    }
    
    virtual ~Transporte() {}
};

#endif