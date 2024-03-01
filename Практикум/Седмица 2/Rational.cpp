#include "Rational.h"
#include <iostream>

Rational::Rational(int _numerator, int _denominator) {
    this->numerator = _numerator;
    this->denominator = _denominator;

    if (this->denominator == 0) {
        throw std::runtime_error("Invalid input! Denominator shouldn't be equal to zero!");
    }
}

void Rational::printRational() const {
    std::cout << this->numerator << "/" << this->denominator << std::endl;
}

Rational Rational::add(const Rational& rhs) {
    Rational addition(0, 1);
    addition.numerator = this->numerator * rhs.denominator + rhs.numerator * this->denominator;
    addition.denominator = this->denominator * rhs.denominator;
    return addition;
}

Rational Rational::subtract(const Rational& rhs) {
    Rational subtraction(0, 1);
    subtraction.numerator = this->numerator * rhs.denominator - rhs.numerator * this->denominator;
    subtraction.denominator = this->denominator * rhs.denominator;
    return subtraction;
}

Rational Rational::multiply(const Rational& rhs) {
    Rational multiplication(0, 1);
    multiplication.numerator = this->numerator * rhs.numerator;
    multiplication.denominator = this->denominator * rhs.denominator;
    return multiplication;
}

Rational Rational::divide(const Rational& rhs) {
    if (rhs.numerator == 0) {
        throw std::runtime_error("Division by zero!");
    }
    Rational division(0, 1);
    division.numerator = this->numerator * rhs.denominator;
    division.denominator = this->denominator * rhs.numerator;
    return division;
}

int Rational::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Rational Rational::simplify() {
    int gcdValue = gcd(this->numerator, this->denominator);
    return Rational(this->numerator / gcdValue, this->denominator / gcdValue);
}
