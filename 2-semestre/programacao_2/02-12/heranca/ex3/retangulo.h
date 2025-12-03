#ifndef RETANGULO__INCLUDED
#define RETANGULO__INCLUDED

#include "forma.h"

#include <string>
#include <iostream>


class Retangulo : public Forma {

private:

public:
    Retangulo(double b, double h) : Forma(b,h){}

    //GETTERS
    virtual double getBase(){
        return base;
    }
    virtual double getAltura(){
        return altura;
    }

    double area() override{
        return base*altura;
    }
};


#endif