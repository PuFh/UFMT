#ifndef MEMBRO_H
#define MEMBRO_H

#include <string>
#include <vector>
#include <iostream>

class Membro {
private:
    int ID;
    std::string Nome;
    std::vector<std::string> LivrosEmprestados;

public:
    Membro(int id, std::string nome) : ID(id), Nome(nome) {}
    
    int getID() const { return ID; }
    std::string getNome() const { return Nome; }
    std::vector<std::string> getLivrosEmprestados() const { return LivrosEmprestados; }
    
    void adicionarLivro(const std::string& isbn) {
        LivrosEmprestados.push_back(isbn);
    }
    
    void removerLivro(const std::string& isbn) {
        for (auto it = LivrosEmprestados.begin(); it != LivrosEmprestados.end(); ++it) {
            if (*it == isbn) {
                LivrosEmprestados.erase(it);
                break;
            }
        }
    }
    
    void exibirDados() const {
        std::cout << "ID: " << ID << " | Nome: " << Nome << " | Livros com o membro: ";
        for (const auto& isbn : LivrosEmprestados) std::cout << isbn << " ";
        std::cout << std::endl;
    }
};

#endif