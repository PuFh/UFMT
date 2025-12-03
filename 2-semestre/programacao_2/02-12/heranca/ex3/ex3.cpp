#include <iostream>
#include <vector>
#include <memory>

#include "forma.h"
#include "circulo.h"
#include "retangulo.h"
#include "triangulo.h"

int main () {
    std::vector < Forma * > formas ;
    formas . push_back (new Circulo (5.0) ) ;
    formas . push_back (new Retangulo (4.0 , 6.0) ) ;
    formas . push_back (new Triangulo (4.0 , 5.0) ) ;
    for ( Forma * forma : formas ) {
        std::cout << " Area : " << forma -> area () << std::endl;
    }
    for ( Forma * forma : formas ) {
        delete forma ;
    }
    return 0;
}