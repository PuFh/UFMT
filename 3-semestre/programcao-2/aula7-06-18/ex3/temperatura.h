#ifndef TEMPERATURA_H
#define TEMPERATURA_H
#include <iostream>

class Temperatura{
private:
float temperaturaCelsius;
float conversaofahrenheit(float temp_celsius); //funccao auxiliar, ela esta private pq n eh pra ninguem chamar ela

public:
//construtor
Temperatura(float t = 25);//valor padrao exigido
//setters(Modificacao)
void alterar(float temp_celsius);

//getters
float getTemperaturaCelsius();
float getTemperaturaFahrenheit();// n eh pra nin


};

#endif