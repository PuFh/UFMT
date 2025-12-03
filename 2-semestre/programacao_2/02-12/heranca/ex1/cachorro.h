#ifndef CACHORRO__INCLUDED
#define CACHORRO__INCLUDED


#include "animal.h"
#include <string>
#include <iostream>


class Cachorro : public Animal{
private:

public:

    void emitirSom() override{
        std::cout <<"Au AU"<< std::endl;
    }

};

#endif