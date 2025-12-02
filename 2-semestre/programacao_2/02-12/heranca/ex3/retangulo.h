#ifndef RETANGULO__INCLUDED
#define RETANGULO__INCLUDED

#include "forma.h"

#include <string>
#include <iostream>


class Circulo : public Forma {

private:

public:

    double area() override{
        f_area = base*altura;
    }
};


#endif