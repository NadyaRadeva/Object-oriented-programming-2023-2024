#include "GCD.h"
#include<iostream>

int main() {
	int a, b;

	do {
		std::cout << "Enter the values of A and B: ";
		std::cin >> a >> b;
	} while (a < 0 || b < 0 || a == 0 && b == 0);

	GCD t(a, b);

	std::cout << t.value() << std::endl;

	return 0;
}
