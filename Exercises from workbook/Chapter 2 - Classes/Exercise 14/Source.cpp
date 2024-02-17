#include "Expr.h"
#include<iostream>

int main() {
	int n;
	do {
		std::cout << "n = ";
		std::cin >> n;
	} while (n < 0);

	double x;
	do {
		std::cout << "x = ";
		std::cin >> x;
	} while (fabs(x) < 0);

	Expr t(n, x);

	std::cout << "S1 = " << t.Ex1() << std::endl;
	std::cout << "S2 = " << t.Ex2() << std::endl;
	std::cout << "S3 = " << t.Ex3() << std::endl;

	return 0;
}
