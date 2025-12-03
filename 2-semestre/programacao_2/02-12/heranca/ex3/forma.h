#ifndef FORMA__INCLUDED
#define FORMA__INCLUDED

#include <string>
#include <iostream>

class Forma{
protected:
    double base, altura;
    
public:
    //CONSTRUTOR
    Forma(double b, double h) : base(b), altura(h){}    


    //GETTERS
    virtual double getBase(){
        return base;
    }
    virtual double getAltura(){
        return altura;
    }
    
    //metodo virtual area
    virtual double area(){
        return base*altura;
    }


};
#endif