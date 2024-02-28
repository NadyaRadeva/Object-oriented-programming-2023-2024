#include "Rational.h"
#include<iostream>

int main() {
	int num1, denom1;
	std::cout << "Enter numerator and denominator of your rational number: ";
	std::cin >> num1 >> denom1;
	if (!std::cin) {
		throw std::runtime_error("Error! Invalid type!");
		return 1;
	}

	Rational r1(num1, denom1);
	r1.printRational();

	int num2, denom2;
	std::cout << "Enter numerator and denominator of your rational number: ";
	std::cin >> num2 >> denom2;
	if (!std::cin) {
		throw std::runtime_error("Error! Invalid type!");
		return 1;
	}

	Rational r2(num2, denom2);
	r2.printRational();

	Rational pr1 = r1.add(r2);
	pr1.simplify();
	pr1.printRational();

	Rational pr2 = r1.subtract(r2);
	pr2.simplify();
	pr2.printRational();

	Rational pr3 = r1.multiply(r2);
	pr3.simplify();
	pr3.printRational();

	Rational pr4 = r1.multiply(r2);
	pr4.simplify();
	pr4.printRational();

	return 1;
}
