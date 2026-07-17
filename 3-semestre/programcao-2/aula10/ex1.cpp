#include <iostream>
#include <string>

using namespace std;

// Classe Base
class Veiculo {
public:
    string marca;

    // Função virtual
    virtual void emitirSom() {
        cout << "O motor do veículo faz: Vruuum!" << endl;
    }
};

// Classe Derivada
class Carro : public Veiculo {
public:
    int numeroPortas;

    // Sobrescrita do método
    void emitirSom() override {
        cout << "Biiiii! Biiiii!" << endl;
    }
};

int main() {
    // Criando um objeto da classe Carro
    Carro carro;

    carro.marca = "Toyota";
    carro.numeroPortas = 4;

    cout << "Marca: " << carro.marca << endl;
    cout << "Número de portas: " << carro.numeroPortas << endl;

    carro.emitirSom();

    return 0;
}