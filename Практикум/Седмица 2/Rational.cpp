#include "Rational.h"
#include<iostream>

Rational::Rational(int _numerator, int _denominator) {
	this->numerator = _numerator;
	this->denominator = _denominator;

	if (this->denominator == 0) {
		throw std::runtime_error("Invalid input! Denominator SHOULDN'T be equal to ZERO!");
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
	Rational division(0, 1);
	division.numerator = this->numerator * rhs.denominator;
	division.denominator = this->denominator * rhs.numerator;
	return division;
}

Rational Rational::simplify() {
	Rational simplified(this->numerator, this->denominator);

	int min = 1;

	if (this->numerator > this->denominator) {
		min = this->denominator;
	}
	else if (this->numerator < this->denominator) {
		min = this->numerator;
	}

	int gcd = min;

	while (gcd > 0) {
		if (this->numerator % gcd == 0 && this->denominator % gcd == 0) {
			break;
		}
		gcd--;
	}

	simplified.numerator = this->numerator / gcd;
	simplified.denominator = this->denominator / gcd;

	return simplified;
}
