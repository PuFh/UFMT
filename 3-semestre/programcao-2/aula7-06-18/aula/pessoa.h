//definicao do biblitoeca pessoa.h
#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa{
private:
    std::string nome;
    int idade;
public:
    Pessoa(std::string n, int i);   //protótipo do construto
    void apresentar();              //Prototipo do metodo
};


#endif