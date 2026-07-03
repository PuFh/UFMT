#include <iostream>
#include <memory>
#include <stack>
#include <string>

int main(){
    std::stack<std::string> editorTexto;
    int opcao;
    std::string palavra;

    while(opcao != 0){
        std::cout <<"\n---Edito de texto---\n";
        std::cout <<"1. Adicionar palavra\n";
        std::cout <<"2. Remover palavra\n";
        std::cout <<"3. ver texto\n";
        std::cout <<"4. ver ultima palavra\n";
        std::cout <<"5. Quantidade de palvras\n";
        std::cout <<"0. Sair\n";
        std::cin >>opcao;
        switch (opcao)
        {
        case 1://push,add
            std::cout<<"Adicione a palavra: ";
            std::cin >> palavra;
            editorTexto.push(palavra);
            break;
        case 2://pop,remove
            std::cout <<"Removendo: "<<editorTexto.top()<<std::endl;
            editorTexto.pop();
            break;
        case 3:{ //a nossa frase
            std::stack<std::string> copia = editorTexto;
            std::stack<std::string> invertida;

            while (!copia.empty()){
                invertida.push(copia.top()); //aqui basicamente estamos pegando valor do topo da copia e coloando como ultimo elemento da invertida
                //pois como a stack funciona com empilhando na hora de remover e retirar, quando formos fazer a impressao ela estara invertida, e conseguiremos imprimir o primiero valor, pois agora ele e o ultimo
                copia.pop();
            }
            //aqui iremos imprimir
            while(!invertida.empty()){
                std::cout <<invertida.top()<<" ";
                invertida.pop();
            }
            break;
        }
        case 4://ultima palavra
            std::cout <<"Ultima palavra digitada: "<<editorTexto.top()<<std::endl;
            break;
        case 5:
            std::cout <<"Quantidade: "<<editorTexto.size()<<std::endl;
            break;
        case 0:
            std::cout <<"Saindo..\n";
            break;
        default:
            std::cout <<"Opcao invalida!\n";
            break;
        }
    }
    return 0;
}