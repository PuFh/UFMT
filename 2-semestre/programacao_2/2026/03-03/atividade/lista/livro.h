#ifndef LIVRO_H
#define LIVRO_H

#include <string>
#include <iostream>

class Livro {
private:
    std::string ISBN;
    std::string Titulo;
    bool Disponivel;

public:
    Livro(std::string isbn, std::string titulo, bool disponivel = true) 
        : ISBN(isbn), Titulo(titulo), Disponivel(disponivel) {}
    
    std::string getISBN() const { return ISBN; }
    std::string getTitulo() const { return Titulo; }
    bool isDisponivel() const { return Disponivel; }
    
    void emprestar() { Disponivel = false; }
    void devolver() { Disponivel = true; }
    
    void exibirDados() const {
        std::cout << "ISBN: " << ISBN << " | Titulo: " << Titulo 
                  << " | Status: " << (Disponivel ? "Disponivel" : "Emprestado") << std::endl;
    }
};

#endif