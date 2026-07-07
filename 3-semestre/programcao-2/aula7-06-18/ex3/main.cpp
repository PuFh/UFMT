#include "temperatura.h"
#include <iostream>

int main(){
    Temperatura termometro;//o objetivo foi basicamente instancio e inicializado dentro do proprio construtor
    int opcao;
    float temperatura;

    while(opcao != 0){
        std::cout <<"----CONTA BANCARIA----"<<std::endl;
        std::cout <<"1. Ver Temperatura(Celsius)"<<std::endl;
        std::cout <<"2. Temperatura(Fahrenheit)"<<std::endl;
        std::cout <<"3. Alterar temperatura"<<std::endl;
        std::cout <<"0. Sair"<<std::endl;
        std::cout <<"-------------\n"<<std::endl;
        std::cout <<"[->";
        std::cin >>opcao;
        switch (opcao){
        case 1:
            std::cout <<"Temperatura(Celsius): "<<termometro.getTemperaturaCelsius()<<std::endl;
            break;
        case 2:
           std::cout <<"Temperatura(Fahrenheit): "<<termometro.getTemperaturaFahrenheit()<<std::endl;
            break;
        case 3:
            std::cout <<"Digite a temperatura(em Celsius): ";
            std::cin >>temperatura;
            termometro.alterar(temperatura);
            break;
        case 0:
            std::cout <<"Saindo..\n";
            break;
        
        default:
            std::cout <<"Opcao invalida!\n";
            break;
        }
    }
    return 0;
}