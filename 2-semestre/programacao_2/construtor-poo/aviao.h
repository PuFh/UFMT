#ifndef AVIAO_H_INCLUDED
#define AVIAO_H_INCLUDED

#include <string>

class Aviao {
public:
    int vel = 0;
    int velMax = 0;
    std::string tipo;
    
     // Construtor parametrizado (protótipo)
    Aviao(int tp);
    
    // Método para imprimir (protótipo)
    void imprimir();
private:
   
};
// Implementação do Construtor
Aviao::Aviao(int tp) {
    // Inicializa vel explicitamente
    vel = 0; 

    if (tp == 1) { // 1=Jato
        tipo = "Jato";
        velMax = 800;
    } else if (tp == 2) { // 2=Monomotor
        tipo = "Monomotor";
        velMax = 550;
    } else if (tp == 3) { // 3=Planador
        tipo = "Planador";
        velMax = 180;
    }
}

// Implementação do Método imprimir
void Aviao::imprimir() {
    std::cout << "Tipo..............: " << tipo << std::endl;
    std::cout << "Velocidade máxima.: " << velMax << std::endl;
    std::cout << "Velocidade atual..: " << vel << std::endl;
}

#endif // AVIAO_H_INCLUDED