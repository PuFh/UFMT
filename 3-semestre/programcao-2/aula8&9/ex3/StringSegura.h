#ifndef STRINGSEGURA_H
#define STRINGSEGURA_H

#include <iostream>
#include <string>

using namespace std;

class StringSegura {

private:
    string texto;

public:
    StringSegura(string t) : texto(t) {}

    StringSegura(StringSegura&&) = default;
    StringSegura& operator=(StringSegura&&) = default;

    StringSegura(const StringSegura&) = delete;
    StringSegura& operator=(const StringSegura&) = delete;

    void mostrar() {
        cout << texto << endl;
    }
};

#endif