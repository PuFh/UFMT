#include <iostream>

//prot
int soma(int, int);

int main(){
    int n1,n2;

    std::cin >>n1;
    std::cin >>n2;

    std::cout <<"Soma: " <<soma(n1,n2) <<std::endl;
    
    return 0;
}
int soma(int v1,int v2){
    int som;
    som = v1 + v2;

    return som;
}
