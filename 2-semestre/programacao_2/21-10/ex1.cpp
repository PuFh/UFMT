#include <iostream>
#include <string>

using namespace std;

string formata_data(const string &dia, const string &mes, const string &ano) {
    return dia + "/" + mes + "/" + ano;
}

int main() {
    string dia, mes, ano;
    cout << "Digite o dia, mes e ano: ";
    cin >> dia >> mes >> ano;

    cout << "Data formatada: " << formata_data(dia, mes, ano) << endl;
    return 0;
}