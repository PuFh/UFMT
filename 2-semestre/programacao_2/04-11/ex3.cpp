#include <iostream>
#include <array>
#include <algorithm> 
#include <format>


int main(){
    constexpr size_t TAM(6);
    std::array<int, TAM> pontuacoes{};

    //impressões dos valores
    for(size_t i{0}; i < TAM; i++){
        std::cin >> pontuacoes.at(i);
    }
    int pontuacaoAlvo = 610;

    //ordenacao
    std::sort(std::begin(pontuacoes), std::end(pontuacoes));

    //impressao
    std::cout << "---PLACAR---" <<std::endl;
    for(const auto &ponto: pontuacoes){
        std::cout << ponto <<std::endl;
    }

    //busca por pontuacaoAlvo
    bool procurar{std::binary_search(std::begin(pontuacoes), std::end(pontuacoes), pontuacaoAlvo)};
    std::cout << " pontuacao  "<< (procurar ? "Encontrada" : "Nao encontrada")<<std::endl;
    
}
