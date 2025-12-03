#include <iostream>
#include "Aviao.h"

using namespace std; // É bom evitar 'using namespace std;' em arquivos .h

int main() {
    // Note o uso de 'new' para alocação dinâmica (ponteiros)
    Aviao *av1 = new Aviao(3); // Planador
    Aviao *av2 = new Aviao(1); // Jato
    Aviao *av3 = new Aviao(2); // Monomotor
    
    av1->imprimir();
    av2->imprimir();
    av3->imprimir();

    // Lembre-se de liberar a memória alocada com 'new'
    delete av1;
    delete av2;
    delete av3;

    return 0;
}