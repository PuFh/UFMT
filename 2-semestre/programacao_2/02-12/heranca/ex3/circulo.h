#ifndef CIRCULO__INCLUDED
#define CIRCUCLO__INCLUDED

#include "forma.h"

#include <string>
#include <iostream>


const double PI = 3.14159265358979323846;
class Circulo : public Forma {

private:
    double raio;
    
public:
    Circulo(double r) : Forma(0,0), raio(r){}

    ////GETTERS

    //metodo virtual area
    double area() override{
        return PI*(raio *raio);
    }
};


#endif