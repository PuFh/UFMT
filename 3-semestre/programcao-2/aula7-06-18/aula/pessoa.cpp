#include "pessoa.h" //a nossa funcao pessoa
#include <iostream>

Pessoa::Pessoa(std::string n, int i){//construtor sendo instanciado
    nome = n;
    idade = i;
}

// Implementação do Método usando o escopo Pessoa::
void Pessoa::apresentar(){
    std::cout << "Nome: " <<nome<<", idade: "<<idade<<" anos."<<std::endl;
}