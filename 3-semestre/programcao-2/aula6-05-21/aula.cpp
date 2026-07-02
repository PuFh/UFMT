#include <iostream>
#include <memory>
#include <list>
#include <queue>
#include <stack>

int main(){
    //std::unique_ptr
    //std::shared_ptr
    //std::weak_ptr

    std::unique_ptr<int> ptr = std::make_unique<int>(42);
    std::cout << *ptr <<std::endl;

    std::shared_ptr<int> a = std::make_shared<int>(10);
    std::shared_ptr<int> b = a;

    //estrutura de dados em C++
    //--lista
    std::list<int> minhaLista;
    minhaLista.push_back(10);//insere no final
    minhaLista.push_front(5);//insere no inicio
    /*
    remocoes
    minhaLista.pop_front()
    minhaLista.pop_back()
    cout <<"Tamanho: " << minhaLista.size() <<endl;
    */

    //--Filas(queue)
    std::queue<int> fila;
    //inserir elementos
    fila.push(10);
    fila.push(12);

    //--Pilha(stack)
    std::stack<int> pilha;

    pilha.push(10);

    
    return 0;
}