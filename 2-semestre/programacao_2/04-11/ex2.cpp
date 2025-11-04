#include <iostream>
#include <vector>
#include <algorithm>    


int main(){
    std::vector<int> leiturasTemp{};
    int valor, i;

    //simulando a coleta de dados
    leiturasTemp.push_back(65);
    leiturasTemp.push_back(70);
    leiturasTemp.push_back(72);

    std::cout <<"Tamanho do vetor: " <<leiturasTemp.size()<<std::endl;

    std::cout <<"Falha de sensor! leitura crítica de 85"<<std::endl;
    leiturasTemp.push_back(85);

    std::cout << leiturasTemp.back()<<std::endl;

    std::cout <<"Expiração da leitura crítica!"<<std::endl;
    leiturasTemp.pop_back();

    //impressao
    for(const auto &temperatura : leiturasTemp){
        std::cout << temperatura <<std::endl;
    }
}