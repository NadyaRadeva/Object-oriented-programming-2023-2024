#ifndef _BANKACCOUNT_H

const int MAX_NAME = 24;
const int MAX_IBAN = 16;

class BankAccount {
private:
	char clientName[MAX_NAME];
	char iban[MAX_IBAN];
	double sum;

public:
	BankAccount(char _clientName[MAX_NAME], char _iban[MAX_IBAN], double _sum);
	void print() const;
	void putIn(double money);
	void withdraw(double money);
};

#endif // !_BANKACCOUNT_H
