#ifndef GATO_HPP
#define GATO_HPP
#include <string>

class Gato{
private:
//atributos
    std::string nome;
    int idade;
    float peso;
public:
    Gato(std::string n, int i, float p);
    void peso_definir(float st_peso);
    void aprensetar(); //facilita para mostrar os atributos
};

#endif