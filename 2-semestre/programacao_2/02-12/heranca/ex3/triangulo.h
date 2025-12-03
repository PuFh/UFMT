#ifndef TRIANGULO__INCLUDED
#define TRIANGULO__INCLUDED

#include "forma.h"

#include <string>
#include <iostream>


class Triangulo : public Forma {

private:

public:
    //contrutor
    Triangulo(double b, double h) : Forma(base, altura){}

    double area() override{
        f_area = (base*altura)/2;
    }
};


#endif