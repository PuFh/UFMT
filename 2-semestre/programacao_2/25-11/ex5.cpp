#include <iostream>
#include <string>

class Aluno {
private:
    std::string nome;
    int matricula;
    std::string curso;
    double nota;

public:
    // Construtor
    Aluno(std::string n, int mat, std::string c, double nt) 
        : nome(n), matricula(mat), curso(c), nota(nt) {}

    // Métodos Get
    std::string getNome() const { return nome; }
    int getMatricula() const { return matricula; }
    std::string getCurso() const { return curso; }
    double getNota() const { return nota; }

    // Métodos Set
    void setNome(std::string n) { nome = n; }
    void setMatricula(int mat) { matricula = mat; }
    void setCurso(std::string c) { curso = c; }
    void setNota(double nt) { nota = nt; }

    // Métodos específicos
    double calcularMedia() const {
        return nota;
    }

    bool verificarAprovacao() const {
        return nota >= 6.0;
    }

    // Método para exibir dados
    void mostrarDados() const {
        std::cout << "Nome: " << nome << ", Matricula: " << matricula 
                  << ", Curso: " << curso << ", Nota: " << nota << std::endl;
    }
};

int main(){
    Aluno a1("Maria Silva", 202345, "Engenharia", 7.5);
    a1.mostrarDados();
    std::cout << "Media: " << a1.calcularMedia() << std::endl;
    std::cout << "Aprovado: " << (a1.verificarAprovacao() ? "Sim" : "Nao") << std::endl;

    return 0;
}