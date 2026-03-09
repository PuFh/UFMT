#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Livro.h"
#include "Membro.h"

class Biblioteca {
private:
    std::vector<Livro> livros;
    std::vector<Membro> membros;

public:
    void registrarLivro(const Livro& l) { livros.push_back(l); }
    void registrarMembro(const Membro& m) { membros.push_back(m); }

    void listarLivros() const {
        for (const auto& l : livros) l.exibirDados();
    }

    void listarMembros() const {
        for (const auto& m : membros) m.exibirDados();
    }

    void emprestarLivro(std::string isbn, int idMembro) {
        Livro* livroAlvo = nullptr;
        Membro* membroAlvo = nullptr;

        for (auto& l : livros) {
            if (l.getISBN() == isbn) {
                livroAlvo = &l;
                break;
            }
        }

        for (auto& m : membros) {
            if (m.getID() == idMembro) {
                membroAlvo = &m;
                break;
            }
        }

        if (livroAlvo && membroAlvo && livroAlvo->isDisponivel()) {
            livroAlvo->emprestar();
            membroAlvo->adicionarLivro(isbn);
            std::cout << "Sucesso!" << std::endl;
        } else {
            std::cout << "Erro no emprestimo." << std::endl;
        }
    }

    void devolverLivro(std::string isbn, int idMembro) {
        for (auto& m : membros) {
            if (m.getID() == idMembro) {
                m.removerLivro(isbn);
                for (auto& l : livros) {
                    if (l.getISBN() == isbn) {
                        l.devolver();
                        break;
                    }
                }
                break;
            }
        }
    }

    void gravarDados() {
        std::ofstream fL("livros.txt");
        for (const auto& l : livros)
            fL << l.getISBN() << " " << l.getTitulo() << " " << (l.isDisponivel() ? "Disponivel" : "Emprestado") << "\n";
        
        std::ofstream fM("membros.txt");
        for (const auto& m : membros) {
            fM << m.getID() << " " << m.getNome();
            for (const auto& isbn : m.getLivrosEmprestados()) fM << " " << isbn;
            fM << "\n";
        }
    }

    void carregarDados() {
        std::ifstream fL("livros.txt");
        std::string i, t, s;
        while (fL >> i >> t >> s) registrarLivro(Livro(i, t, s == "Disponivel"));

        std::ifstream fM("membros.txt");
        std::string linha;
        while (std::getline(fM, linha)) {
            std::stringstream ss(linha);
            int id; std::string nome, isbn;
            ss >> id >> nome;
            Membro m(id, nome);
            while (ss >> isbn) m.adicionarLivro(isbn);
            registrarMembro(m);
        }
    }
};

int main() {
    Biblioteca b;
    b.carregarDados();
    int op;
    do {
        std::cout << "\n1.Reg Livro\n2.Reg Membro\n3.Listar Livros\n4.Listar Membros\n5.Emprestar\n6.Devolver\n7.Sair\nOpcao: ";
        std::cin >> op;
        if (op == 1) {
            std::string i, t; std::cout << "ISBN e Titulo: "; std::cin >> i >> t;
            b.registrarLivro(Livro(i, t));
        } else if (op == 2) {
            int id; std::string n; std::cout << "ID e Nome: "; std::cin >> id >> n;
            b.registrarMembro(Membro(id, n));
        } else if (op == 3) b.listarLivros();
        else if (op == 4) b.listarMembros();
        else if (op == 5) {
            std::string i; int id; std::cout << "ISBN e ID Membro: "; std::cin >> i >> id;
            b.emprestarLivro(i, id);
        } else if (op == 6) {
            std::string i; int id; std::cout << "ISBN e ID Membro: "; std::cin >> i >> id;
            b.devolverLivro(i, id);
        }
    } while (op != 7);
    b.gravarDados();
    return 0;
}