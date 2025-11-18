#include <iostream>

class Aluno{
    public:
        std::string nome;
        int matricula;
        int idade;
        double mediafinal;

        //metodo de leitura
        void leituraAluno(std::string la_nome, int la_matricula, int la_idade){
             std::cout << "-------Leitura Aluno-------" << std::endl;
            std::cout << "Nome: \n";
            nome = la_nome;

            std::cout <<"Matricula: \n";
            matricula = la_matricula;

            std::cout <<"Idade: \n";
            idade = la_idade;
        }
        void
};

class Disciplina{
    public:
        std::string nome;
        int hcarga, codigo;
        double min_nota;
};