#ifndef PAGAMENTO__INCLUDED
#define PAGAMENTO__INCLUDED

#include <string>
#include <iostream>

class Empregado{
protected:
    double salario;

public:
    Empregado(double s): salario(s){}

    //metodo virtual calcular salario
    virtual double getSalarioMensal(){
        return salario;
    }
    //imprimir salario
    virtual void imprimirDetalhes(){
        std::cout <<"----"<<std::endl;
        std::cout << "Salario: " << salario <<std::endl;
    }
};


#endif