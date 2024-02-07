#include<iostream>

const int SIZE = 16;
const int MAX_SIZE = 20;

struct Person {
	char firstName;
	char surname;
};

void readPerson(Person& p) {
	std::cout << "Enter first name of the person: ";
	std::cin >> p.firstName;
	std::cout << "Enter surname of the person: ";
	std::cin >> p.surname;
}

void printPerson(const Person& p) {
	std::cout << "First name of the person: " << p.firstName << std::endl;
	std::cout << "Surname of the person: " << p.surname << std::endl;
}



struct Client {
	Person name;
	double sum;
};

void readClient(Client& c) {
	std::cout << "Name of client: " << std::endl;
	readPerson(c.name);
	std::cout << "Money of the client: ";
	std::cin >> c.sum;
}

void printClient(const Client& c) {
	std::cout << "Name of client: " << std::endl;
	printPerson(c.name);
	std::cout << "Money of the client: " << c.sum << std::endl;
}



int main() {
	std::cout << "Enter the number of clients: ";
	int size;
	std::cin >> size;
	if (!std::cin || size <= 0) {
		throw std::runtime_error("Error! Invalid input!");
		return 1;
	}

	Client* clients = new Client[size];

	std::cout << "Input all of your clients: " << std::endl;
	for (size_t i = 0; i < size; ++i) {
		readClient(clients[i]);
	}

	std::cout << "Clients of the bank: " << std::endl;
	for (size_t i = 0; i < size; ++i) {
		printClient(clients[i]);
	}

	double s = 0;
	for (size_t i = 0; i < size; ++i) {
		if (clients[i].sum < 0) {
			s += clients[i].sum;
		}
	}
	std::cout << "The sum of all of clients' duties is: " << s << std::endl;

	delete clients;

	return 0;
}
