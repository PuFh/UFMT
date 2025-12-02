#include <iostream>
#include "aviao.h"

using namespace std; // É bom evitar 'using namespace std;' em arquivos .h

int main() {
    // Note o uso de 'new' para alocação dinâmica (ponteiros)
    Aviao av1{};// Planador
    Aviao av2{};  // Jato
    Aviao av3{}; // Monomotor
    
    av1.
    av2.imprimir();
    av3.imprimir();


    Aviao av4{};

    av4.imprimir();
    // Lembre-se de liberar a memória alocada com 'new'
    delete av1;
    delete av2;
    delete av3;

    return 0;
}