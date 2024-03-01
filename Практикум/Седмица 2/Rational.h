#ifndef _RATIONAL_

class Rational {
private:
	int numerator;
	int denominator;

	int gcd(int a, int b);

public:
	Rational(int _numerator, int _denominator);

	void printRational() const;

	Rational add(const Rational& rhs);
	Rational subtract(const Rational& rhs);
	Rational multiply(const Rational& rhs);
	Rational divide(const Rational& rhs);

	Rational simplify();
};

#endif // !_RATIONAL_
