#include <iostream>
#include <memory>
#include <queue>

int main(){
    std::queue<std::string> fila;
    int opcao;
    std::string doc;

    while(opcao != 0){
        std::cout <<"\n--Sistema de Documentos--\n";
        std::cout <<"1. Adicionar documento(entrar na fila)\n";
        std::cout <<"2. Processar documento(sair na fila)\n";
        std::cout <<"3. Ver proximo da fila\n";
        std::cout <<"4. Quantidade de documentos(tamanho da fila)\n";
        std::cout <<"0. Sair\n";
        std::cout <<"->";
        std::cin >>opcao;

        switch (opcao){
        case 1:
            std::cout <<"Nome do documento: ";
            std::cin >> doc;
            fila.push(doc); //aqui entra na fila
            std::cout << "Documento \"" << doc << "\" adicionado.\n";

            break;
        case 2:
            if(!fila.empty()){
                std::cout <<"Processado: "<< fila.front() << std::endl;
                fila.pop();
            }else{
                std::cout <<"Lista vazia\n";
            }
            break;
        case 3:
            if(!fila.empty())
                std::cout <<"Proximo documento: "<<fila.front() <<std::endl;
            else
                std::cout <<"Fila vazia!\n";
            break;
        case 4:
            std::cout <<"Tamanho da fila: "<<fila.size()<<std::endl;
            break;
        case 0:
            std::cout <<"Encerrando...\n";
            break;
        
        default:
            std::cout <<"Opcao invalida!\n";
            break;
        }
    }


    return 0;
}