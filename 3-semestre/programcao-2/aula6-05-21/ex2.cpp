#include <iostream>
#include <memory>
#include <list>

int main(){
    std::list<int> myList;
    int opcao,valor;

    
    std::cout <<"----LISTA----"<<std::endl;
    std::cout <<"1. inserir inicio"<<std::endl;
    std::cout <<"2. inserir fim"<<std::endl;
    std::cout <<"3. remove inicio"<<std::endl;
    std::cout <<"4. remove fim"<<std::endl;
    std::cout <<"5. tamanho da lista"<<std::endl;
    std::cout <<"6. Sair"<<std::endl;
    std::cout <<"-------------\n"<<std::endl;
    while(opcao != 6){
        std::cout <<"->";
        std::cin >>opcao;
        
        switch (opcao)
        {
        case 1://insere inicio
        std::cout <<"\nValor a ser inserido:";
        std::cin >>valor;

        myList.push_front(valor);
            
        break;

        case 2://insere fim
        std::cout <<"\nValor a ser inserido:";
        std::cin >>valor;
        myList.push_back(valor);
        break;

        case 3://remove fim
        myList.pop_front();

        break;
        case 4://remove inicio
        myList.pop_back();
        break;

        case 5:
        std::cout <<"\nTamanho da lista: "<<myList.size()<<std::endl;  
        break;

        case 6:
        std::cout <<"Saindo...\n";
        break;

        default:
        std::cout <<"\nValor invalidado\n";
            break;
        }
        //Valore dentro da lista

    }

    

    return 0;
}