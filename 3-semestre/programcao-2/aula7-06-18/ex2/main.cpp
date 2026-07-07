#include "contaBancaria.h"
#include <iostream>

int main(){
    CONTABANCARIA usuario1(2341, 0);//usuario
    int opcao;
    double p;

    while(opcao != 0){
        std::cout <<"----CONTA BANCARIA----"<<std::endl;
        std::cout <<"1. Ver saldo"<<std::endl;
        std::cout <<"2. Depositar"<<std::endl;
        std::cout <<"3. Sacar"<<std::endl;
        std::cout <<"0. Sair"<<std::endl;
        std::cout <<"-------------\n"<<std::endl;
        std::cout <<"[->";
        std::cin >>opcao;
        switch (opcao){
        case 1:
            std::cout << "Saldo: "<<usuario1.get_saldo()<<std::endl;
            break;
        case 2:
            std::cout <<"Valor a depositar: ";
            std::cin >> p;
            usuario1.set_depositar(p);
            break;
        case 3:
            std::cout <<"Valor a sacar: ";
            std::cin >> p;
            usuario1.set_sacar(p);
            break;
        case 0:
            std::cout <<"Saindo..\n";
            break;
        
        default:
            std::cout <<"Opcao invalida!\n";
            break;
        }
    }

}