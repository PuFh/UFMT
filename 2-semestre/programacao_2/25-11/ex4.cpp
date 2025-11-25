#include <iostream>
#include <string>

class Carro {
private:
    std::string marca;
    std::string modelo;
    int ano;
    double quilometragem;

public:
    // Construtor
    Carro(std::string ma, std::string mo, int a, double km) 
        : marca(ma), modelo(mo), ano(a), quilometragem(km) {}

    // Métodos Get
    std::string getMarca() const { return marca; }
    std::string getModelo() const { return modelo; }
    int getAno() const { return ano; }
    double getQuilometragem() const { return quilometragem; }

    // Métodos Set
    void setMarca(std::string ma) { marca = ma; }
    void setModelo(std::string mo) { modelo = mo; }
    void setAno(int a) { ano = a; }
    void setQuilometragem(double km) { quilometragem = km; }

    // Método para dirigir
    void dirigir(double km) {
        if (km > 0) {
            quilometragem += km;
        }
    }

    // Método para exibir dados
    void mostrarDados() const {
        std::cout << "Marca: " << marca << ", Modelo: " << modelo 
                  << ", Ano: " << ano << ", Quilometragem: " << quilometragem 
                  << std::endl;
    }
};

int main(){
    Carro car1("Toyota", "Corolla", 2020, 15000);
    car1.mostrarDados();
    car1.dirigir(500);
    car1.mostrarDados();

    return 0;
}