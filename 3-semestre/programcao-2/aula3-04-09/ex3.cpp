#include <iostream>

int main(){
    int n,soma;

    std::cin >> n;

    soma = 0;//para n ter lixo de memoria
    if( n > 100 ){
        std::cout <<"Valor muito grande!\n";
        return false;
    }
    for(int i = 1; i < n;i++){
        if(n%i == 0){
            soma +=i;
        }
    }
    if(soma == n){
        std::cout <<"Numero perfeito\n";
    }else{
        std::cout <<"Nao eh perfeitoz\n";
    }
    return 0;

}