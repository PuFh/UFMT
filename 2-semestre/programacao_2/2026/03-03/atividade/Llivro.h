#ifndef LIVRO__INCLUDED
#define LIVRO__INCLUDED

#include <string>
#include <iostream>
#include <vector>

class Livro{
protected:
    int ISBN;
    std::string titulo;
    bool disponivel;

public:
    Livro(int isbn, std::string titulo, bool disp): ISBN(isbn), titulo(titulo), disponivel(disp){}

    
    //fazendo os metodos
    int getISBN (){
        return ISBN;
    }
    std::string getTitulo() {
        return titulo;
    }
    bool isDiponivel(){
        return disponivel;
    }
    int emprestar(){
        if(disponivel){
            disponivel = false;
            std::cout <<"Livro emprestadp!\n";
        }else{
            std::cout <<"Livro não disponivel.\n";
        }
    }
    int devolver(){
        if(!disponivel){
            disponivel = true;
            std::cout <<"livro devolvido.\n";
        }else{
            std::cout<<"O livro já foi devolvido.\n";
        }
    }
    int exibirDados(){
        std::cout <<"Titulo: "<<titulo<<" | ISBN: "<<ISBN<<" | disponivel: "<<isDiponivel<<std::endl
    }

};
#endif