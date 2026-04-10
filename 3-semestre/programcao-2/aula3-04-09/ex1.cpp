#include <iostream>
#include <string>

int main(){
    int idade, nivel;
    bool autorizacao;
    std::string at;

    std::cout << "Digite  a sua idade: "<<std::endl;
    std::cin>>idade;
    std::cin.ignore(1000, '\n'); 
    

    if(idade < 16){
        std::cout <<"Acesso negado!"<<std::endl;
        return 0;
    }

    std::cout <<"Voce tem autorizacao?"<< std::endl;
    std::getline(std::cin, at);

    if((at == "sim" || at == "s")){
        autorizacao = 1;
    }
    else{
        autorizacao = 0;
    }
    //condicao para sim

    if((16 <= idade <=17 && autorizacao) || idade > 17){
        std::cout <<"Digite o nivel" <<std::endl;
        std::cin >>nivel;
        std::cin.ignore(1000, '\n'); 

        switch (nivel){
        case 1:
            std::cout <<"NIvel basico";
            break;
        case 2:
            std::cout <<"NIvel intermediario";
            break;
        case 3:
            std::cout <<"NIvel avancado";
            break;
        default:
            std::cout <<"Opcao invalida";
            break;
        }
    }else{
        std::cout <<"N tem autorizacao"<<std::endl;
    }
    return 0;

}