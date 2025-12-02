#ifndef FORMA__INCLUDED
#define FORMA__INCLUDED

#include <string>
#include <iostream>

class Forma{
protected:
    double base, altura, f_area;
    
public:
    //CONSTRUTOR
    Forma(double b, double h) : base(b), altura(h){}    


    //metodo virtual area
    virtual double area(){
        f_area = base*altura;
    }

    //GETTERS
    virtual double getBase(){
        return base;
    }
    virtual double getAltura(){
        return altura;
    }

};
#endif