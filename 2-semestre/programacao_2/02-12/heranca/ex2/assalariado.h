#ifndef ASSALARIADO__INCLUDED
#define ASSALARIADO__INCLUDED

#include <string>
#include <iostream>

#include "pagamento.h"

class EmpregadoAssalariado : public Empregado{
private:


public:
    EmpregadoAssalariado(double s): Empregado(s){}


    //metodo virtual calcular salario
    double getSalarioMensal() override{
        return salario;
    }
    //imprimir salario
    void imprimirDetalhes() override{
        std::cout <<"----"<<std::endl;
        std::cout << "Empregado Assalariado, Salario Mensal: " << salario <<std::endl;
    }
    
};


#endif