#ifndef GATO__INCLUDED
#define GATO__INCLUDED


#include "animal.h"
#include <string>
#include <iostream>


class Gato : public Animal{
private:

public:
    

    void emitirSom() override{
        std::cout <<"MIAU"<< std::endl;
    }

};

#endif