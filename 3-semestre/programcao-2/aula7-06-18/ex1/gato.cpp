#include "gato.hpp"
#include <iostream>

Gato::Gato(std::string n, int i, float p){
    nome = n;
    idade = i;
    peso_definir(p);
}

void Gato::peso_definir(float st_peso){
    if(st_peso <= 0){
        std::cout << "Peso invalido\n";
        return;
    }else{
        peso = st_peso;
    }
}

void Gato::aprensetar(){
    std::cout << "Nome: "<<nome<<", idade: "<<idade<<", peso: "<<peso<<std::endl;
}