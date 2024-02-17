#include "Employee.h"
#include<iostream>
#include<iomanip>

void Employee::read() {
	std::cout << "First name: ";
	std::cin >> name.first;
	std::cout << "Surname: ";
	std::cin >> name.last;
	std::cout << "Work hours: ";
	std::cin >> work.hours;
	std::cout << "Wage for 1 hour: ";
	std::cin >> work.wage;
}

void Employee::print() const {
	std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2);
	std::cout << name.first << " " << name.last << " " << work.hours * work.wage << std::endl;
}
