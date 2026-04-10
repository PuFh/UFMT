#include <iostream>
#

int main(){
    int saldo, menu,ax;
    saldo = 1000;//saldo inicial
    bool condi = 1;

    while(condi){
        std::cout <<"-------------"<<std::endl;
        std::cout <<"1. ver saldo"<<std::endl;
        std::cout <<"2. Depositar"<<std::endl;
        std::cout <<"3. Sacar"<<std::endl;
        std::cout <<"4. Sair"<<std::endl;
        std::cout <<"-------------"<<std::endl;
        std::cin >>menu;
        switch(menu){
        case 1:
            //ver saldo
            std::cout << "Saldo Atual: "<< saldo<<std::endl;

            break;
        case 2:
            //depositar
            std::cout <<"Valor a ser depositado: ";
            std::cin >>ax;
            saldo += ax;
            break;
        case 3:
            //sacar
            std::cout <<"valor a ser sacado: ";
            std::cin >> ax;
            //condicao caso o valor seja maior q tem na conta
            if(ax > saldo){
                std::cout <<"Valor a ser sacado insuficiente" << std::endl;
                
            }else{
                saldo -= ax;
            }
            break;
        case 4:
            //sair
            return 1;
            break;
        default:
            std::cout <<"Opcao invalida, selecione uma das opcoes"<< std::endl;
            break;
        }

    }


}