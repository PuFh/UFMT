#include <iostream>


class Sala{
    public:
        int identificador;
        int capacidade;
        bool disponibilidade;

    bool reservar(int qtd_aluno){
        if(disponibilidade = true && capacidade >= qtd_aluno){
            disponibilidade = false;
            return 1;
        }else{
            return 0;
        }
    }
    void liberar(){
        if(disponibilidade = false){
            disponibilidade = true;
        }
    }

    bool consultarDisponibilidade(){
        if(disponibilidade == true){
            std::cout<<"Esta sala esta disponivel!"<<std::endl;
            return disponibilidade;

        }else{
            std::cout<<"Esta sala esta indisponivel"<<std::endl;
            return disponibilidade;
        }
    }

};

class Usuarios{
    public:
        std::string nome;
        std::string tipo;//se eh aluno,professor etc...

        void imprimir(){
            std::cout << "Nome: " << nome <<std::endl;
            std::cout << "Tipo: " << tipo <<std::endl;
        }
        void cadastrar(){
            std::cout << "Nome: " <<std::endl;
            std::getline(std::cin, nome);
            std::cout << "Tipo: " <<std::endl;
            std::getline(std::cin, tipo);
        }
};

int main(){
    Usuarios alunos,professores;
    Sala sala1;

    professores.cadastrar();
}