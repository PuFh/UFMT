#include <iostream>
#include <vector>
#include <memory>

#include "pagamento.h"
#include "assalariado.h"
#include "horista.h"

int main () {
    std::vector <std::shared_ptr< Empregado>> empregados;
    empregados.push_back ( std::make_shared < EmpregadoAssalariado >(3000.00) ) ;
    empregados.push_back ( std::make_shared < EmpregadoHorista >(160 , 25.00) ) ;

    for ( const auto & empregado : empregados ) {
        empregado -> imprimirDetalhes () ;
        std::cout << "Salario Mensal : " << empregado->getSalarioMensal () << std::endl ;
    }
    return 0;
}