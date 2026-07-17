#include "Contador.h"

int main() {

    Contador c(10);

    cout << "Valor inicial: ";
    c.mostrar();

    ++c;

    cout << "Depois do ++c: ";
    c.mostrar();

    c++;

    cout << "Depois do c++: ";
    c.mostrar();

    return 0;
}