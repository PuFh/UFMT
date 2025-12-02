#ifndef VACA__INCLUDED
#define VACA__INCLUDED


#include "animal.h"
#include <string>
#include <iostream>


class Vaca : public Animal{
private:

public:

    void emitirSom() override{
        std::cout <<"Muuu"<< std::endl;
    }

};

#endif