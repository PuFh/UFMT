#include <iostream>

using namespace std;


int calcular_potencia(int base,int expoente){
    int resultado, i;
    resultado = 1;
    i=0;
    while( i < expoente){
        resultado = resultado*base;
        i++;
    }
    return resultado;
}
int main(){
    int b, e;

    cout <<"Digite o valor da base: \n";
    cin >> b;
    cout <<"Digite o valor do expoente: \n";
    cin >> e;
    
    cout <<"O valor eh "<<calcular_potencia(b,e);


    return 0;
}
