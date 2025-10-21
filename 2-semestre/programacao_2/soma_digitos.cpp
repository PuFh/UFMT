#include <iostream>
using namespace std;

int main(){
    int n, soma = 0, deno, resto;

    cout << "Digite um valor para N:\n";
    cin >> n;

    deno = n;
    while (deno != 0){
        resto = deno % 10;
        soma += resto;
        deno = deno / 10;
    }

    cout << "A soma dos valores de " << n << " é: " << soma << endl;
}