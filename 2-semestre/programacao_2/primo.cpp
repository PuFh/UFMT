#include <iostream>
using namespace std;

int eh_primo(int n){
    int divisao;
    for (int i = 2; i < n; i++){
        divisao = n % i;
        if (divisao == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int primo;
    cout << "Digite um número:\n";
    cin >> primo;

    if (eh_primo(primo)){
        cout << "O valor é primo\n";
    } else {
        cout << "O valor não é primo\n";
    }
}