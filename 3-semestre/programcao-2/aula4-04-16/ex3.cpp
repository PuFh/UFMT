#include <iostream>

//prototipo
inline double conversor(int);

int main(){
    double qua_dolar,n1;

    std::cout <<"Digite o valor em dolar\n";
    std::cin >>qua_dolar;
    std::cout << "Valor convertido: "<<conversor(qua_dolar)<<std::endl;

    /*teste do inline
    std::cin >>n1;
    std::cout << "valor teste: "<<conversor(n1);
    */
    return 1;
}

inline double conversor(int valor){
    double qua_real;

    qua_real = valor*4.85;

    return qua_real;
}