#include "Fact.h"
#include<iostream>

int main() {
	int a;

	do {
		std::cout << "Enter the value of a: ";
		std::cin >> a;
	} while (a <= 0);

	Fact t(a);

	std::cout << t.value() << std::endl;

	return 0;
}
