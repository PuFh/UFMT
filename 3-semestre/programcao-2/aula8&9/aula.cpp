#include <iostream>
#include <string>

class Gato{
private:
    std::string nome;
    int idade;
    float peso;
public:
    //construtor
    Gato(std::string n, int i, float p) : nome(n), idade(i), peso(p){}

    int getIdade(){return idade;}
    float getPeso(){return peso;}
    void apresentar(){
        std::cout <<"Informacoes do gato\nNome: "<<nome<<" Idade: "<<idade<<
        " peso: "<<peso<<std::endl;
    }
    //destrutor
    ~Gato(){

        std::cout << "Gato destruido\n";
    }
};


//exemplos onde a lista de inicializacao eh obrigatoria
//com consts
class Exemplo {
    const int id;
public:
    Exemplo(int i) : id(i) {} // obrigatório, não dá pra fazer id = i; no corpo
};

int main(){
    Gato gato1("milena", 3,3.7);

    gato1.apresentar();
    return 0;
}