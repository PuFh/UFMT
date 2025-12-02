#ifndef HORISTA__INCLUDED
#define HORISTA__INCLUDED

#include <string>
#include <iostream>

#include "pagamento.h"

class EmpregadoHorista : public Empregado{
private:
    int horas;
    double v_horas;
    

public:
    EmpregadoHorista(double v_h, int h): Empregado(0),horas(h),v_horas(v_h){}

    //metodo virtual calcular salario
    double getSalarioMensal() override{
        return {salario = v_horas*horas};
    }
    //imprimir salario
    void imprimirDetalhes() override{
        std::cout <<"----"<<std::endl;
        std::cout << "Empregado Horista, Horas Trabalhadas: "<< horas <<" Taxa por Hora: 25" << v_horas <<std::endl;
    }
    
};


#endif