#include "temperatura.h"
#include <iostream>

Temperatura::Temperatura(float t){
    temperaturaCelsius = t;
}

void Temperatura::alterar(float temp_celsius){
    if(temp_celsius < -273.15){//bloqueio
        std::cout <<"Valor nemo que -273.15\n";
    }else{
        temperaturaCelsius = temp_celsius;
    }
}


float Temperatura::conversaofahrenheit(float temp_celsius){
    return (temp_celsius * 1.8) +32;
}

float Temperatura::getTemperaturaCelsius(){
    return temperaturaCelsius;
}
float Temperatura::getTemperaturaFahrenheit(){
    return Temperatura::conversaofahrenheit(temperaturaCelsius); //assim retornamos sem precisar de um artibuto
}

void aprensetar(){

}