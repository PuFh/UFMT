#ifndef TRIANGULO__INCLUDED
#define TRIANGULO__INCLUDED

#include "forma.h"

#include <string>
#include <iostream>


class Triangulo : public Forma {

private:

public:
    //contrutor
    Triangulo(double b, double h) : Forma(b,h){}

    //GETTERS
    virtual double getBase(){
        return base;
    }
    virtual double getAltura(){
        return altura;
    }

    double area() override{
        return (base*altura)/2;
    }
};


#endif