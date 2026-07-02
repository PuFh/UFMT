#include <iostream>

int main(){
    int x,y;//declaracao das variaveis
    int* ptr;
    //inicializacao das variaveis x e y
    x = 10;
    y = 20;

    //conteúdo dessas variáveis e seus respectivos endereços
    ptr = &x;
    std::cout<<"endereco de x: "<<ptr<<std::endl;
    std::cout<<"conteudo de x: "<<*ptr<<std::endl;

    ptr = &y;
    std::cout<<"endereco de y: "<<ptr<<std::endl;
    std::cout<<"conteudo de y: "<<*ptr<<std::endl;


    return 0;
}