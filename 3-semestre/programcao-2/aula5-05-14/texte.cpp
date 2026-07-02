#include <iostream>

void incrementa(int* p){

    *p = *p+1;
    return;
}

int main(){
    int x = 10;

    std::cout<<"Valor de X: "<<x<<std::endl;
    incrementa(&x);
    std::cout<<"Valor de X: "<<x<<std::endl;

    return 0;
}