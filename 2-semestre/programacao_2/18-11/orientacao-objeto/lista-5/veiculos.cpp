#include <iostream>


class Veiculo{
    public:
        std::string placa;
        std::string modelo;
        std::string tipo;
        int fab;
        double quilometragem;
        bool status;//em operação(true) ou em manutenção(false)

        void atualizarQuilometragem(){
            quilometragem = 0.0;
        }
        bool alterarStatus(){
            if(status == true){
                status = false;
                std::cout << "Veiculo em manutenção" << std::endl;
                return status;
            }
            else{
                status = true;
                std::cout << "Veiculo em Operando" << std::endl;
                return status;
            }
        }
        //metodos básicos
    void cadastrarVeiculo(std::string novaPlaca, std::string novaModelo,std::string novaTipo, int novoFab, double novaQuilo){
            std::cout << "-------Cadastro Veiculo-------" << std::endl;
            std::cout << "Placa: \n";
            placa = novaPlaca;

            std::cout << "Modelo: \n";
            modelo = novaModelo;
            
            std::cout << "Tipo: \n";
            tipo = novaTipo; 

            std::cout << "Ano de Fabricacao: \n";
            fab = novoFab;

            std::cout << "Quilometragem do veiculo: \n";
            quilometragem = novaQuilo;

        }
        void imprimirVeiculo(){
            std::cout << "-------IMPRESSAO Veiculo-------" << std::endl;
            std::cout << "Placa: " << placa << std::endl;
            std::cout << "Modelo: " << modelo << std::endl;
            std::cout << "Tipo: " << tipo << std::endl;
            std::cout << "Fabricacao: " << fab << std::endl;
            std::cout << "quilometragem percorrida: " << quilometragem << std::endl;
        }
};

class Motorista{
    public:
        std::string nome;
        int id;
        int idade;
        char cnh;

        void cadastrarMotorista(std::string novoNome,  int novaIdade, int novoId, char novaCnh){
            std::cout << "-------Cadastro Motorista-------" << std::endl;

            std::cout << "Nome do motorista: \n";
            nome = novoNome;

            std::cout << "idade do motorista: \n";
            idade = novaIdade;

            std::cout << "Identificacao do motorista: \n";
            id = novoId;

            std::cout << "Qual o tipo da carteira do motorista(A-E): \n";
            cnh = novaCnh;
        }

        void imprimirVeiculo(){
            std::cout << "-------IMPRESSAO Motorista-------" << std::endl;
            std::cout << "Nome: " << nome << std::endl;
            std::cout << "id: " << id << std::endl;
            std::cout << "idade: " << idade << std::endl;
            std::cout << "Tipo CNH: " << cnh << std::endl;
        }
};

void operar(Veiculo veiculo, Motorista motorista){
    if(veiculo.tipo == "carro" && (motorista.cnh == 'B' || motorista.cnh == 'C')){
        std::cout <<"Este motorista esta apto para dirigir este veiculo!";
        return;
    }
    else if(veiculo.tipo == "caminhao" && (motorista.cnh == 'D' || motorista.cnh == 'E')){
        std::cout <<"Este motorista esta apto para dirigir este veiculo!";
        
    }else{
        std::cout <<"Este motorista nao esta apto para dirigir este veiculo!";
    }
    
    

}

int main(){
    Veiculo carro, caminhao;
    Motorista pessoa1;

    //placa,modelo,ano,quilo
    carro.cadastrarVeiculo("34vnb","opala","carro",1945,145.654);
    //nome, idade, id, cnh
    pessoa1.cadastrarMotorista("Felipe", 34, 453, 'B');

    
    carro.imprimirVeiculo();
    pessoa1.imprimirVeiculo();

    operar(carro, pessoa1);
    
    
    
}