#include <iostream>
#include <vector>

#include "transporte.h"
#include "carro.h"
#include "bicicleta.h"
#include "aviao.h"

int main() {
    // Vetor de ponteiros para a classe base (Polimorfismo)
    std::vector<Transporte*> transportes;

    // Adiciona instâncias das classes derivadas
    transportes.push_back(new Carro());
    transportes.push_back(new Bicicleta());
    transportes.push_back(new Aviao());

    // Percorre o vetor chamando os métodos virtuais
    for (Transporte* t : transportes) {
        t->iniciar();
    }

    std::cout << "---" << std::endl; // Separador

    for (Transporte* t : transportes) {
        t->parar();
    }

    // Liberação de memória
    for (Transporte* t : transportes) {
        delete t;
    }

    return 0;
}