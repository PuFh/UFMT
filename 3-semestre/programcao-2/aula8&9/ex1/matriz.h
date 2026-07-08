#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz{
private:
    int** matriz;
    int linhas;
    int colunas;

public:
    Matriz(int l, int c) : linhas(l), colunas(c) {}
    ~Matriz();
    Matriz(const Matriz& outra); //construtor de copia
};




#endif