#include "Angle.h"
#include<iostream>

int main() {
	Angle degree1;
	std::cout << "Enter the value of your degree: ";
	double deg1;
	std::cin >> deg1;
	degree1.setValue(deg1);

	std::cout << "sin(" << deg1 << ") = " << degree1.getSin() << std::endl;
	std::cout << "cos(" << deg1 << ") = " << degree1.getCos() << std::endl;
	std::cout << "tan(" << deg1 << ") = " << degree1.getTan() << std::endl;

	return 0;
}
