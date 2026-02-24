#ifndef VETOR2D_H
#define VETOR2D_H

#include <iostream>

class Vetor2D {
private:
    float x, y; // Attributes 

public:
    Vetor2D(float x = 0, float y = 0) : x(x), y(y) {}

    // Operator Overloading Prototypes
    Vetor2D operator+(const Vetor2D& other) const; // [cite: 8]
    bool operator==(const Vetor2D& other) const;    // 

    // Friend function for std::cout [cite: 10]
    friend std::ostream& operator<<(std::ostream& os, const Vetor2D& v);
};

#endif