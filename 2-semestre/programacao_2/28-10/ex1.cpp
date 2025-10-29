#include <iostream>
#include <cstdlib>
#include <ctime>

void registrarEventos (){
    static int id_eventos = 0;
    int codigo = rand();//codigo receba a cada chamada um novo valor
    std::cout <<"Evento: "<<id_eventos<<std::endl;
    std::cout << "Codigo: "<< codigo << std::endl;
    
    

    id_eventos++;
}

int main(){
    srand ( time (0) );

    int i;


    i = 0;
    while(i < 5){
        registrarEventos();
        i++;
    }
}