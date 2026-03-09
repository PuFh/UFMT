#ifndef MEMBRO__INCLUDED
#define MEMBRO__INCLUDED

#include <string>
#include <iostream>
#include <vector>

//biblioteca livro
#include "livro.h"

class Membro{
protected:
    int ID;
    std::string nome;
    std::vector<Livro> LivrosEmprestados;

public:
    Membro(int id, std::string n, std::vector<std::string> LivrosEmp): ID(id), nome(n),LivrosEmprestados(LivrosEmp){}
    
    //fazendo os metodos
    int getID() {
        return ID;
    }
    std::string getNome() {
        return nome;
    }
    std::vector<Livro> getLivroEmprestado() {
        return LivrosEmprestados;
    }
    void adicionarLivro(const std::string& isbn) {
            LivrosEmprestados.push_back(isbn);
    }
    

};
#endif