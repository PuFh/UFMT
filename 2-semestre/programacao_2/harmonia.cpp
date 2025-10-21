#include <iostream>

using namespace std;

int main(){
    int n;
    float soma;

    cout <<"Digite um valor para n: \n";
    cin >> n;
    soma = 0;
    for(int i = 1; i <= n; i++){
        soma = soma+(1.0/i);
    }
    cout <<"O valor da serie harmonica eh: "<<soma;

    return 0;
}