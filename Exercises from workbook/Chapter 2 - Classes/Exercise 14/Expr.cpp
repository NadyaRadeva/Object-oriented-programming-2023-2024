#include "Expr.h"

Expr::Expr(int _n, double _x) {
	this->n = _n;
	this->x = _x;
}

double Expr::Ex1() const {
	double s = 1, x1 = 1;
	for (size_t i = 1; i <= n; ++i) {
		x1 = x1 * x / i;
		s += x1;
	}

	return s;
}

double Expr::Ex2() const {
	double s = 1, x1 = 1;
	for (size_t i = 1; i <= 2 * n; i = i + 2) {
		x1 = -x1 * x * x / (i * (i + 1));
		s += x1;
	}

	return s;
}

double Expr::Ex3() const {
	double s = x, x1 = x;
	for (size_t i = 2; i <= 2 * n; i = i + 2) {
		x1 = -x1 * x * x / (i * (i + 1));
		s += x1;
	}

	return s;
}
