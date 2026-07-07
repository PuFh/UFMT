#ifndef TEMPERATURA_H
#define TEMPERATURA_H
#include <iostream>

class Temperatura{
private:
float temperaturaCelsius;

public:
//construtor
Temperatura(float t = 25);//valor padrao exigido
//setters(Modificacao)
void alterar(float temp_celsius);

//getters
float getTemperaturaCelsius();
float getTemperaturaFahrenheit();

float conversaofahrenheit(float temp_celsius); //funccao auxiliar

};

#endif