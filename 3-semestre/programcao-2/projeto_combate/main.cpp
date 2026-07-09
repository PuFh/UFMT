#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <locale>
#include "Personagem.hpp"
#include "Personagens.hpp"

int main() {
    std::setlocale(LC_ALL, "pt_BR.UTF-8");
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<Personagem*> lutadores;
    lutadores.push_back(new Scorpion());
    lutadores.push_back(new SubZero());
    lutadores.push_back(new LiuKang());
    lutadores.push_back(new Raiden());
    lutadores.push_back(new ShaoKahn());
    lutadores.push_back(new Kitana());
    lutadores.push_back(new Mileena());
    lutadores.push_back(new SonyaBlade());
    lutadores.push_back(new Jade());
    lutadores.push_back(new Sindel());

    std::cout << "=========================================\n";
    std::cout << "   MORTAL KOMBAT - SIMULACAO DE COMBATE  \n";
    std::cout << "=========================================\n\n";

    //Escolha do Modo de Jogo
    int modoOpcao = 0;
    while (modoOpcao != 1 && modoOpcao != 2) {
        std::cout << "Selecione o modo de jogo:\n";
        std::cout << "1. Jogar contra o BOT (Computador)\n";
        std::cout << "2. Jogar contra outro PLAYER (Jogador 2)\n";
        std::cout << "Escolha (1 ou 2): ";
        std::cin >> modoOpcao;
        if (modoOpcao != 1 && modoOpcao != 2) {
            std::cout << "Opção inválida! Tente novamente.\n\n";
        }
    }
    bool contraBot = (modoOpcao == 1);

    //Menu de Personagens
    std::cout << "\n=========================================\n";
    std::cout << "        LUTADORES DISPONIVEIS\n";
    std::cout << "=========================================\n";
    for (size_t i = 0; i < lutadores.size(); ++i) {
        std::cout << i + 1 << ". " << lutadores[i]->getNome() 
                  << " [HP: " << lutadores[i]->getHp() 
                  << " | ATQ: " << lutadores[i]->getForcaAtaque() 
                  << " | DEF: " << lutadores[i]->getDefesa() << "]\n";
    }
    std::cout << "=========================================\n";

    //Escolha do Jogador 1
    int escolhaP1 = 0;
    while (escolhaP1 < 1 || escolhaP1 > 10) {
        std::cout << "\n[JOGADOR 1] Escolha seu personagem (1-10): ";
        std::cin >> escolhaP1;
        if (escolhaP1 < 1 || escolhaP1 > 10) {
            std::cout << "Número inválido!";
        }
    }
    Personagem* p1 = lutadores[escolhaP1 - 1]; // Subtrai 1 para virar o índice correto (0 a 9)
    
    //Oponente, bot ou p2
    Personagem* p2 = nullptr;
    if (contraBot) {
        int indexBot = std::rand() % 10;
        p2 = lutadores[indexBot];
        std::cout << "\nO Computador (BOT) escolheu: " << p2->getNome() << "\n";
    } else {
        int escolhaP2 = 0;
        while (escolhaP2 < 1 || escolhaP2 > 10) {
            std::cout << "\n[JOGADOR 2] Escolha seu personagem (1-10): ";
            std::cin >> escolhaP2;
            if (escolhaP2 < 1 || escolhaP2 > 10) {
                std::cout << "Número inválido!";
            }
        }
        p2 = lutadores[escolhaP2 - 1];
    }

    // Garante vida cheia para começar
    p1->restaurarVida();
    p2->restaurarVida();

    std::cout << "\n=========================================\n";
    std::cout << "      QUE COMECE O COMBATE: " << p1->getNome() << " VS " << p2->getNome() << "\n";
    std::cout << "=========================================\n\n";

    //Loop de Combate em Turnos
    int rodada = 1;
    while (p1->estaVivo() && p2->estaVivo()) {
        std::cout << "--- RODADA " << rodada << " ---\n";

        // JOGADOR 1
        int acaoP1 = 0;
        while (acaoP1 != 1 && acaoP1 != 2) {
            std::cout << "Turno de " << p1->getNome() << " (JOGADOR 1):\n";
            std::cout << "1. Golpe Normal\n";
            std::cout << "2. Golpe Especial [" << p1->getNomeGolpeEspecial() << "]\n";
            std::cout << "Escolha (1-2): ";
            std::cin >> acaoP1;
        }
        
        int danoP1 = (acaoP1 == 1) ? p1->executarGolpeNormal() : p1->executarGolpeEspecial();
        p2->receberDano(danoP1);

        if (!p2->estaVivo()) break; // Se J2 morreu, a luta acaba aqui

        std::cout << "\n";

        //JOGADOR 2 ou BOT
        int acaoP2 = 0;
        if (contraBot) {
            std::cout << "Turno do BOT (" << p2->getNome() << "):\n";
            acaoP2 = (std::rand() % 2) + 1; // Sorteia puramente 1 ou 2
        } else {
            while (acaoP2 != 1 && acaoP2 != 2) {
                std::cout << "Turno de " << p2->getNome() << " (JOGADOR 2):\n";
                std::cout << "1. Golpe Normal\n";
                std::cout << "2. Golpe Especial [" << p2->getNomeGolpeEspecial() << "]\n";
                std::cout << "Escolha (1-2): ";
                std::cin >> acaoP2;
            }
        }

        int danoP2 = (acaoP2 == 1) ? p2->executarGolpeNormal() : p2->executarGolpeEspecial();
        p1->receberDano(danoP2);

        std::cout << "\n=========================================\n\n";
        rodada++;
    }

    //Fim de Jogo
    std::cout << "\n=========================================\n";
    std::cout << "              FIM DE JOGO                \n";
    std::cout << "=========================================\n";
    if (p1->estaVivo()) {
        std::cout << "VENCEDOR: " << p1->getNome() << " (JOGADOR 1)!\n";
    } else {
        if (contraBot) std::cout << "VENCEDOR: " << p2->getNome() << " (BOT)!\n";
        else std::cout << "VENCEDOR: " << p2->getNome() << " (JOGADOR 2)!\n";
    }

    // Limpeza de memória
    for (auto l : lutadores) delete l;

    return 0;
}