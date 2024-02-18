#include "Differ.h"
#include<iostream>

int main() {
	int n;
	do {
		std::cout << "n = ";
		std::cin >> n;
	} while (n < 1);

	Differ t(n);

	std::cout << "Elements in the array " << t.diff() ? "are different. \n" : "are not different.\n";

	return 0;
}
