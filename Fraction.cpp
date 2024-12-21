#include "Fraction.h"


int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a < 0 ? -a : a; 
}


Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    reduce();
}


void Fraction::reduce() {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
    if (denominator < 0) { 
        numerator = -numerator;
        denominator = -denominator;
    }
}


int Fraction::getNumerator() const {
    return numerator;
}


int Fraction::getDenominator() const {
    return denominator;
}


int Fraction::getWholePart() const {
    return numerator / denominator;
}


Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}

Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Division by zero.");
    }
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}


Fraction& Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    ++(*this);
    return temp;
}

Fraction& Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction temp = *this;
    --(*this);
    return temp;
}


bool Fraction::operator>(const Fraction& other) const {
    return numerator * other.denominator > other.numerator * denominator;
}

bool Fraction::operator>=(const Fraction& other) const {
    return *this > other || *this == other;
}

bool Fraction::operator<(const Fraction& other) const {
    return !(*this >= other);
}

bool Fraction::operator<=(const Fraction& other) const {
    return !(*this > other);
}


Fraction::operator double() const {
    return static_cast<double>(numerator) / denominator;
}


std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    os << frac.numerator << "/" << frac.denominator;
    return os;
}