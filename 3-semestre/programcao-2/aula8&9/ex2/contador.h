#ifndef CONTADOR_H
#define CONTADOR_H

#include <iostream>
using namespace std;

class Contador {

private:
    int valor;

public:
    Contador(int v = 0) {
        valor = v;
    }

    Contador& operator++() {
        ++valor;
        return *this;
    }

    Contador operator++(int) {
        Contador copia = *this;
        valor++;
        return copia;
    }

    void mostrar() {
        cout << valor << endl;
    }
};

#endif