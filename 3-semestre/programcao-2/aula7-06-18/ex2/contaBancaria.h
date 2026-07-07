#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H
#include <iostream>

class CONTABANCARIA{
private:
    int numeroConta;
    double saldo;
public:
    //contrutos
    CONTABANCARIA(int n, double s);
    //setter
    void set_depositar(double p);
    void set_sacar(double p);
    //getters
    double get_saldo();

};

#endif