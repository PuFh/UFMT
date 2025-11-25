#include <iostream>
#include <string>

class Produto {
private:
    std::string nome;
    double preco;
    int quantidade;

public:
    // Construtor
    Produto(std::string n, double p, int q) : nome(n), preco(p), quantidade(q) {}

    // Métodos Get
    std::string getNome() const { return nome; }
    double getPreco() const { return preco; }
    int getQuantidade() const { return quantidade; }

    // Métodos Set
    void setNome(std::string n) { nome = n; }
    void setPreco(double p) { preco = p; }
    void setQuantidade(int q) { quantidade = q; }

    // Métodos para gerenciar estoque
    void adicionarEstoque(int qtd) {
        if (qtd > 0) {
            quantidade += qtd;
        }
    }

    void removerEstoque(int qtd) {
        if (qtd > 0 && quantidade >= qtd) {
            quantidade -= qtd;
        }
    }

    // Método para exibir dados
    void mostrarDados() const {
        std::cout << "Nome: " << nome << ", Preco: " << preco 
                  << ", Quantidade: " << quantidade << std::endl;
    }
};

int main(){
    Produto p1("Notebook", 2500.0, 10);
    p1.mostrarDados();
    p1.adicionarEstoque(5);
    p1.removerEstoque(3);
    p1.mostrarDados();

    return 0;
}