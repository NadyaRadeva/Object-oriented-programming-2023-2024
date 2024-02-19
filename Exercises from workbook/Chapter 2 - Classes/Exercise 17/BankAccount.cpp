#include "BankAccount.h"
#include<cstring>
#include<iostream>

BankAccount::BankAccount(char _clientName[MAX_NAME], char _iban[MAX_IBAN], double _sum) {
	strcpy_s(this->clientName, _clientName);
	this->clientName[MAX_NAME - 1] = '\0';
	strcpy_s(this->iban, _iban);
	this->iban[MAX_IBAN - 1] = '\0';
	this->sum = _sum;
}

void BankAccount::print() const {
	std::cout << "Name of the client: " << this->clientName << std::endl;
	std::cout << "IBAN of the client: " << this->iban << std::endl;
	std::cout << "Amount of money in the client's bank account: " << this->sum << std::endl;
}

void BankAccount::putIn(double money) {
	if (money >= 0) {
		this->sum = this->sum + money;
	}
	else {
		std::cout << "You are trying to put in an incorrect amount of money!" << std::endl;
	}
}

void BankAccount::withdraw(double money) {
	if (money < 0) {
		std::cout << "You are trying to withdraw an incorrect amount of money!" << std::endl;
	}
	else {
		if (money > this->sum) {
			std::cout << "You are trying to withdraw more than you have in your account!" << std::endl;
		}
		else {
			this->sum = this->sum - money;
		}
	}
}
