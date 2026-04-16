#include <iostream>

int main(){
    int n,soma;

    std::cin >> n;

    if( n > 100 ){
        std::cout <<"Valor muito grande!\n";
        return 0;
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