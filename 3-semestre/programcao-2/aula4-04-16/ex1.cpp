#include <iostream>

typedef struct data{
    int dia,mes,ano;
}data;

int main(){
    data calendario;
    
    std::cout << "Digite o dia,mes,ano\n";
    std::cin >> calendario.dia >> calendario.mes >> calendario.ano;

    if(calendario.dia > 31 || calendario.mes > 12){
        std::printf("Valores invalidos!\n");
        return 0;
    }

    std::printf("%d/%d/%d",calendario.dia,calendario.mes,calendario.ano);
    

    return 0;
}