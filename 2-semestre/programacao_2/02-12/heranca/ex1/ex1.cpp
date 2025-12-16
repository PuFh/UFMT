#include <iostream>
#include <vector>

#include "animal.h"
#include "cachorro.h"
#include "gato.h"
#include "vaca.h"

//Hierarquia de Animais

int main () {
    Cachorro cachorro{};
    Gato gato{};
    Vaca vaca{};
    
    std::vector < Animal * > animais ;
    animais.push_back(& cachorro ) ;
    animais.push_back(& gato ) ;
    animais.push_back(& vaca ) ;
    for ( Animal *animal : animais ) {
        animal->emitirSom();
    }
    return 0;
}