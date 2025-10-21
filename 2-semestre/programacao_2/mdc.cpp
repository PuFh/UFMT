#include <iostream>
using namespace std;

int mdc(int a, int b){
    int r, resultado;
    while (r != 0){
        r = a % b;
        resultado = b;
        a = b;
        b = r;
    }
    return resultado;
}

int main(){
    int n1, n2;
    cout << "Digite o valor de a:\n";
    cin >> n1;
    cout << "Digite o valor de b:\n";
    cin >> n2;

    cout << "O MDC é " << mdc(n1, n2) << "\n";
}