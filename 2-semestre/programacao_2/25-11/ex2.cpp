#include <iostream>
#include <string>

class Livro {
private:
    std::string titulo;
    std::string autor;
    int anoPublicacao;
    int numPaginas;

public:
    // Construtor
    Livro(std::string t, std::string a, int ano, int pag) 
        : titulo(t), autor(a), anoPublicacao(ano), numPaginas(pag) {}

    // Métodos Get
    std::string getTitulo() const { return titulo; }
    std::string getAutor() const { return autor; }
    int getAnoPublicacao() const { return anoPublicacao; }
    int getNumPaginas() const { return numPaginas; }

    // Métodos Set
    void setTitulo(std::string t) { titulo = t; }
    void setAutor(std::string a) { autor = a; }
    void setAnoPublicacao(int ano) { anoPublicacao = ano; }
    void setPaginas(int pag) { numPaginas = pag; }

    // Método para exibir dados
    void mostrarDados() const {
        std::cout << "Titulo: " << titulo << ", Autor: " << autor 
                  << ", Ano: " << anoPublicacao << ", Paginas: " << numPaginas 
                  << std::endl;
    }
};

int main(){
    Livro l1("1984", "George Orwell", 1949, 328);
    l1.mostrarDados();
    Livro l2("Fogo Morto", "Graciliano Ramos", 1933, 229);
    l2.mostrarDados();
    l2.setPaginas(299);
    l2.mostrarDados();

    return 0;
}