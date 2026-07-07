#include "contaBancaria.h"
#include <iostream>

//inicializando o construtor
CONTABANCARIA::CONTABANCARIA(int n, double s){
    numeroConta = n;
    saldo = s;
}
//funcoes
void CONTABANCARIA::set_depositar(double p){
    saldo += p;
}
void CONTABANCARIA::set_sacar(double p){
    if(p > saldo){
        std::cout<<"Valor insuficiente para sacar!\n";
    }else{
        saldo -= p;
    }
}
double CONTABANCARIA::get_saldo(){
    return saldo;
}