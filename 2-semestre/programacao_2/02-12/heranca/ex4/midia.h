#ifndef MIDIA__INCLUDED
#define MIDIA__INCLUDED

#include <string>
#include <iostream>

class Midia {
protected:
    std::string titulo;
    std::string autor; // Para Livro ou Artista/Diretor para CD/DVD

public:
    // Construtor
    Midia(const std::string& t, const std::string& a) : titulo(t), autor(a) {}

    // Metodos Virtuais Puros (idealmente) ou com implementacao padrao
    virtual void exibirInfo() const {
        std::cout << "Midia: " << titulo << " por " << autor << std::endl;
    }
    
    virtual void reproduzir() const {
        std::cout << "Reproduzindo midia generica..." << std::endl;
    }
    
    // Destrutor virtual para evitar vazamento de memória ao deletar
    virtual ~Midia() {}
};

#endif