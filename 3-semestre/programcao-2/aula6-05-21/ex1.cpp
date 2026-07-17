#include <iostream>
#include <memory>

int main(){
    /*
    int* ptr = new int(42);
    std::cout << "Valor de ptr "<<*ptr<<std::endl;
    delete ptr;
    */
   std::unique_ptr<int> ptr = std::make_unique<int>(42);
   std::cout << "Valor de ptr: "<<*ptr<<std::endl;
   //este codigo faz a mesma coisa que o de cima, faz uma alocacao dinamica de memoria para ptr do tipo int de ponteiro e logo em seguida quando chega no fim do escopo(funcao main) ele deleta o ponteiro automaticamente
   return 0;
}