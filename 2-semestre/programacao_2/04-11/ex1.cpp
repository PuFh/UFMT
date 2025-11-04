#include <iostream>
#include <array>
#include <algorithm>    


int main(){
    constexpr size_t num_produtos(5);
    constexpr double imposto = 0.15;
    double preco_final{0};
    std::array<double, num_produtos> precosBase{};

    for (size_t i{0}; i < precosBase.size(); i++){
        std::cout << "Valor na posicao "<< i+1 <<": ";
        std::cin >> precosBase.at(i);
    }
    //impressão e calculo do preço final
    for (const auto &produto : precosBase){
        preco_final = produto*(1+0.15);
        std::cout <<"Valor Base: "<<produto<<"| Valor Final: "<<preco_final<<std::endl;
    }

}