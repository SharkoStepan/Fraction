#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int numerator;   
    int denominator; 

    void reduce();    

public:
    
    Fraction(int num = 0, int denom = 1);

    int getNumerator() const;
    int getDenominator() const;
    int getWholePart() const;

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    Fraction& operator++(); 
    Fraction operator++(int); 
    Fraction& operator--(); 
    Fraction operator--(int); 

    bool operator>(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;

    operator double() const;

    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
};

#endif // FRACTION_H