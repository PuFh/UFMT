#include <iostream>

void processarDados() {

    int *dadosImportantes = new int(100);//Memory Leak, criando um ponteiro e não sendo utilizado.

    int *valorTemporario = new int(42);
    delete valorTemporario;
    std::cout << "Valor (apos delete): " << *valorTemporario << std::endl;//Use-After-Free , esta usando o ponteiro apos ter limpado ele
    valorTemporario = nullptr;

    //Double Free (voce esta deletenado o valor de 2 vetores que se recebem)
    int* ptrOriginal = new int(99);
    int* ptrCopia = ptrOriginal;
    delete ptrOriginal;
    delete ptrCopia;

}

int main() {
    processarDados();
    std::cout << "Programa concluiu." << std::endl;
    return 0;
}