#ifndef PERSONAGENS_HPP
#define PERSONAGENS_HPP

#include "Personagem.hpp"

//scorpion
class Scorpion : public Personagem {
public:
    Scorpion() : Personagem("Scorpion", 100, 25, 12) {}
    int executarGolpeNormal() override { 
        return forcaAtaque * 1.0; 
    }
    int executarGolpeEspecial() override { 
        return forcaAtaque * 1.5; // Multiplicador 1.5x
    } 
    std::string getNomeGolpeEspecial() override { 
        return "Toasty! (Fogo Infernal)"; 
    }
};

//subzero
class SubZero : public Personagem {
public:
    SubZero() : Personagem("Sub-Zero", 105, 22, 14) {}
    int executarGolpeNormal() override { 
        return forcaAtaque * 1.0; 
    }
    int executarGolpeEspecial() override { 
        return forcaAtaque * 1.4; 
    } 
    std::string getNomeGolpeEspecial() override { 
        return "Congelamento Profundo"; 
    }
};

//liukang
class LiuKang : public Personagem {
public:
    LiuKang() : Personagem("Liu Kang", 100, 26, 11) {}
    int executarGolpeNormal() override { 
        return forcaAtaque * 1.0; 
    }
    int executarGolpeEspecial() override { 
        return forcaAtaque * 1.6; 
    } 
    std::string getNomeGolpeEspecial() override { 
        return "Chute de Bicicleta Voador"; 
    }
};

//raiden
class Raiden : public Personagem {
public:
    Raiden() : Personagem("Raiden", 110, 24, 13) {}
    int executarGolpeNormal() override { 
        return forcaAtaque * 1.0; 
    }
    int executarGolpeEspecial() override { 
        return forcaAtaque * 1.45; 
    }
    std::string getNomeGolpeEspecial() override { 
        return "Choque do Deus do Trovao"; 
    }
};

// Shao Kahn, o chefao
class ShaoKahn : public Personagem {
public:
    ShaoKahn() : Personagem("Shao Kahn", 130, 28, 15) {}
    int executarGolpeNormal() override { 
        return forcaAtaque * 1.1; 
    } 
    int executarGolpeEspecial() override { 
        return forcaAtaque * 1.7; 
    }
    std::string getNomeGolpeEspecial() override { 
        return "Martelo da Ira (Wrath Hammer)"; 
    }
};


class Kitana : public Personagem {
public:
    Kitana() : Personagem("Kitana", 95, 24, 12) {}
    int executarGolpeNormal() override { 
        return forcaAtaque * 1.0; 
    }
    int executarGolpeEspecial() override { 
        return forcaAtaque * 1.5; 
    }
    std::string getNomeGolpeEspecial() override { 
        return "Lançamento de Leques Cortantes"; 
    }
};

class Mileena : public Personagem {
public:
    Mileena() : Personagem("Mileena", 95, 27, 10) {}
    int executarGolpeNormal() override { 
        return forcaAtaque * 1.0; 
    }
    int executarGolpeEspecial() override { 
        return forcaAtaque * 1.65; 
    }
    std::string getNomeGolpeEspecial() override { 
        return "Mordida Feroz Tarkatana"; 
    }
};

class SonyaBlade : public Personagem {
public:
    SonyaBlade() : Personagem("Sonya Blade", 100, 23, 13) {}
    int executarGolpeNormal() override { 
        return forcaAtaque * 1.0; 
    }
    int executarGolpeEspecial() override { 
        return forcaAtaque * 1.4; 
    }
    std::string getNomeGolpeEspecial() override { 
        return "Anéis de Energia Sônicos"; 
    }
};

class Jade : public Personagem {
public:
    Jade() : Personagem("Jade", 100, 22, 14) {}
    int executarGolpeNormal() override { 
        return forcaAtaque * 1.0; 
    }
    int executarGolpeEspecial() override { 
        return forcaAtaque * 1.45; 
    }
    std::string getNomeGolpeEspecial() override { 
        return "Bastao Imperial Relampago"; 
    }
};

class Sindel : public Personagem {
public:
    Sindel() : Personagem("Sindel", 105, 25, 11) {}
    int executarGolpeNormal() override { 
        return forcaAtaque * 1.0; 
    }
    int executarGolpeEspecial() override { 
        return forcaAtaque * 1.55; 
    }
    std::string getNomeGolpeEspecial() override { 
        return "Grito Banshee Ultrassônico"; 
    }
};

#endif