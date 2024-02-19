#include "BankAccount.h"
#include<iostream>
#include<cstring>

int main() {
	char clientName[MAX_NAME];
	char iban[MAX_IBAN];
	double sum;

	std::cout << "Enter the client's name: ";
	std::cin.getline(clientName, MAX_NAME);
	std::cout << "Enter the client's IBAN: ";
	std::cin.getline(iban, MAX_IBAN);
	std::cout << "Enter the size of client's account: ";
	std::cin >> sum;
	if (!std::cin || sum < 0) {
		throw std::runtime_error("Invalid input!");
		return 1;
	}

	BankAccount x(clientName, iban, sum);
	x.print();

	std::cout << std::endl;

	std::cout << "Enter the amount of money you want to put in the account: ";
	double money1;
	std::cin >> money1;
	if (!std::cin) {
		throw std::runtime_error("Invalid input!");
		return 1;
	}
	x.putIn(money1);
	x.print();

	std::cout << "Enter the amount of money you want to withdraw: ";
	double money2;
	std::cin >> money2;
	if (!std::cin) {
		throw std::runtime_error("Invalid input!");
		return 1;
	}
	x.withdraw(money2);
	x.print();

	return 0;
}
