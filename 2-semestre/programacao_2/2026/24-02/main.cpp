#include <iostream>
#include "Vetor2D.h"

int main() {
    Vetor2D v1(10.5, 20.0);
    Vetor2D v2(5.0, 10.0);
    
    Vetor2D v3 = v1 + v2; // Testing + [cite: 15]

    std::cout << "Resultado: " << v3 << std::endl; // Testing << [cite: 15]

    if (v1 == v2) { // Testing == [cite: 15]
        std::cout << "Iguais" << std::endl;
    } else {
        std::cout << "Diferentes" << std::endl;
    }

    return 0;
}