#include <iostream>
#include <string>

class ContaBancaria {
private:
    std::string numeroConta;
    double saldo;
    std::string titular;

public:
    // Construtores
    ContaBancaria(std::string num, double s, std::string tit) 
        : numeroConta(num), saldo(s), titular(tit) {}
    
    ContaBancaria(std::string num, std::string tit) 
        : numeroConta(num), saldo(0.0), titular(tit) {}

    // Métodos Get
    std::string getNumeroConta() const { return numeroConta; }
    double getSaldo() const { return saldo; }
    std::string getTitular() const { return titular; }

    // Métodos Set
    void setNumeroConta(std::string num) { numeroConta = num; }
    void setTitular(std::string tit) { titular = tit; }

    // Métodos para operações bancárias
    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
        }
    }

    double sacar(double valor) {
        if (valor > 0 && saldo >= valor) {
            saldo -= valor;
            return valor;
        }
        return 0.0;
    }

    // Método para exibir dados
    void mostrarDados() const {
        std::cout << "Conta: " << numeroConta << ", Titular: " << titular 
                  << ", Saldo: " << saldo << std::endl;
    }
};

int main(){
    ContaBancaria c1("12345-6", 1000.0, "Joao Silva");
    c1.mostrarDados();
    c1.depositar(500.0);
    auto valor = c1.sacar(300.0);
    if (valor > 0)
        std::cout << "Saque de R$ " << valor << " efetuado com sucesso" << std::endl;
    else
        std::cout << "Saldo insuficiente" << std::endl;
    c1.mostrarDados();
    
    ContaBancaria c2("789-0", "Pedro Martins");
    c2.mostrarDados();
    auto valor2 = c2.sacar(100.0);
    if (valor2 > 0)
        std::cout << "Saque de R$ " << valor2 << " efetuado com sucesso" << std::endl;
    else
        std::cout << "Saldo insuficiente" << std::endl;


    return 0;
}