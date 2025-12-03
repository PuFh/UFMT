#include <iostream>
#include <vector>

#include "midia.h"
#include "livro.h"
#include "cd.h"
#include "dvd.h"

int main() {
    // Vetor de ponteiros para a classe base (Polimorfismo)
    std::vector<Midia*> midias;

    midias.push_back(new Livro("O Senhor dos Aneis", "J.R.R. Tolkien"));
    midias.push_back(new CD("Thriller", "Michael Jackson"));
    midias.push_back(new DVD("Inception", "Christopher Nolan"));


    for (Midia* m : midias) {
        m->exibirInfo();
    }
    std::cout << std::endl; // Separador

    for (Midia* m : midias) {
        m->reproduzir();
    }

    // Liberação de memória
    for (Midia* m : midias) {
        delete m;
    }

    return 0;
}