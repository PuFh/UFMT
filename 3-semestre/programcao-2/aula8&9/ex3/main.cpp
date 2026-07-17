#include "StringSegura.h"
#include <utility>

int main() {

    StringSegura s1("Programacao II");

    s1.mostrar();

    // StringSegura s2 = s1; // Erro
    // s2 = s1;              // Erro

    StringSegura s3(std::move(s1));

    s3.mostrar();

    return 0;
}