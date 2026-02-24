#include "Vetor2D.h"

// Soma (+): (x1+x2, y1+y2) [cite: 8]
Vetor2D Vetor2D::operator+(const Vetor2D& other) const {
    return Vetor2D(this->x + other.x, this->y + other.y);
}

// Igualdade (==): Returns true if coordinates are identical 
bool Vetor2D::operator==(const Vetor2D& other) const {
    return (this->x == other.x && this->y == other.y);
}

// Saída (<<): Format (x, y) [cite: 10]
std::ostream& operator<<(std::ostream& os, const Vetor2D& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}