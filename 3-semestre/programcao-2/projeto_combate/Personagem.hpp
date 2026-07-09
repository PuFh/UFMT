#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <string>
#include <iostream>

class Personagem {
protected:
    std::string nome;
    int hp;
    int maxHp;
    int forcaAtaque;
    int defesa;

public:
    Personagem(std::string nome, int hp, int forcaAtaque, int defesa)
        : nome(nome), hp(hp), maxHp(hp), forcaAtaque(forcaAtaque), defesa(defesa) {}

    virtual ~Personagem() {}

    // Getters e Setters (Encapsulamento)
    std::string getNome() { 
        return nome; 
    }
    int getHp() { 
        return hp; 
    }
    int getMaxHp() { 
        return maxHp; 
    }
    int getForcaAtaque() { 
        return forcaAtaque; 
    }
    int getDefesa() { 
        return defesa; 
    }
    
    void setHp(int novoHp) { 
        hp = novoHp; 
        if (hp < 0) 
            hp = 0;
    }

    // Métodos virtuais puros (Polimorfismo)
    virtual int executarGolpeNormal() = 0;
    virtual int executarGolpeEspecial() = 0;
    virtual std::string getNomeGolpeEspecial() = 0;

    // Lógica comum para receber dano descontando a defesa
    virtual void receberDano(int danoBruto) {
        int danoEfetivo = danoBruto - defesa;
        if (danoEfetivo < 5) danoEfetivo = 5; // Garante dano mínimo caso a defesa seja muito alta
        
        setHp(hp - danoEfetivo);
        std::cout << nome << " recebeu " << danoEfetivo << " de dano! (HP atual: " << hp << "/" << maxHp << ")\n";
    }

    bool estaVivo() const { 
        return hp > 0; 
    }
    void restaurarVida() { 
        hp = maxHp; 
    }
};

#endif