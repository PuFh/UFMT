#include <iostream>

int main(){
    int x,y;
    //variaveis sendo atribuidas valores
    x = 11;
    y = 22;
    std::cout << "\nvalor de X "<<x;
    std::cout << "\nvalor de Y "<<y;

    int* xptr; // ponteiro chamado xptr para inteiro
    int* yptr;

    xptr = &x;//atribui  o conteudo de x a xptr
    yptr = &y;//mesma coisa

    std::cout << "\nEndereco de x = "<< &x;
    std::cout << "\nEndereco de y = "<< &y;
    std::cout << "\nvalor de xptr = "<<xptr;
    std::cout << "\nvalor de yptr = "<<yptr;
    std::cout << "\nvalor de *xptr = "<<*xptr;
    std::cout << "\nvalor de *yptr = "<<*yptr;
    std::cout <<std::endl;

    int array[3] = {1,2,3};
    int* ptr = array;

    std::cout <<ptr[0]<<std::endl;


    //-------ALOCACAO DINAMICA
    int *p = new int;//aloca um inteiro
    *p  =   42;
    std::cout   <<*p<<std::endl;
    delete p;
    //para um array dinamico
    int *v = new int[5]; // Aloca array de 5 inteiros
    for (int i = 0; i < 5; i++) v[i] = i * 2;
    delete[] v; // Liberta o array


    return 0;
}