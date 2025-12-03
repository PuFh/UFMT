#ifndef AVIAO_H_INCLUDED
#define AVIAO_H_INCLUDED

#include <string>
#include <iostream>

class Aviao {
private: // Mova os atributos para a seção privada (Encapsulamento!)
    int vel;
    int velMax;
    std::string tipo;

public:
    // Construtor parametrizado (apenas o protótipo)
    Aviao(int tp, int vmax, std::string type){
        if (tp == 1) {
        tipo = "Jato";
        velMax = 800;
    } else if (tp == 2) {
        tipo = "Monomotor";
        velMax = 550;
    } else if (tp == 3) {
        tipo = "Planador";
        velMax = 180;
    }
    }
    // Implementação do Construtor(default)
    Aviao() {
        vel = 100;
        velMax = 800;
        tipo = "jato";
    }
    
    //geters
    // string getNome(){
        //return nome;
    }
    //seters
    

// Implementação do Método imprimir
    void imprimir() {
        std::cout <<""<<std::endl;
        std::cout << "Tipo..............: " << tipo << std::endl;
        std::cout << "Velocidade máxima.: " << velMax << std::endl;
        std::cout << "Velocidade atual..: " << vel << std::endl;
        std::cout <<""<<std::endl;
    }
};
#endif // AVIAO_H_INCLUDED