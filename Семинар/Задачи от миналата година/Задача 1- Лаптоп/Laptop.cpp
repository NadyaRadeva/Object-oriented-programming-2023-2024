#include "Laptop.h"
#include<iostream>
#include<cstring>

void Laptop::copy(Laptop const& other) {
	this->brand = new char[strlen(other.brand) + 1];
	strcpy_s(this->brand, strlen(other.brand) + 1, other.brand);

	this->model = new char[strlen(other.model) + 1];
	strcpy_s(this->model, strlen(other.model) + 1, other.model);

	this->price = other.price;
	this->screenSize = other.screenSize;
	this->clockSpeed = other.clockSpeed;
	this->casheSize = other.casheSize;
	this->coreNums = other.coreNums;
	this->RAMSize = other.RAMSize;
	this->batteryCapacity = other.batteryCapacity;
}

void Laptop::erase() const {
	delete[] this->brand;
	delete[] this->model;
}

Laptop::Laptop() {
	this->brand = nullptr;
	this->model = nullptr;
	this->price = 0;
	this->screenSize = 0;
	this->clockSpeed = 0;
	this->casheSize = 0;
	this->coreNums = 0;
	this->RAMSize = 0;
	this->batteryCapacity = 0;
}

Laptop::Laptop(char* _brand, char* _model, double _price, double _screenSize, double _clockSpeed, unsigned int _casheSize, unsigned int _coreNums, unsigned int _RAMSize, unsigned int _batteryCapacity) {
	this->brand = new char[strlen(_brand) + 1];
	strcpy_s(this->brand, strlen(_brand) + 1, _brand);

	this->model = new char[strlen(_model) + 1];
	strcpy_s(this->model, strlen(_model) + 1, _model);

	this->price = _price;
	this->screenSize = _screenSize;
	this->clockSpeed = _clockSpeed;
	this->casheSize = _casheSize;
	this->coreNums = _coreNums;
	this->RAMSize = _RAMSize;
	this->batteryCapacity = _batteryCapacity;
}

Laptop::~Laptop() {
	this->erase();
}

Laptop::Laptop(Laptop const& other) {
	this->copy(other);
}

Laptop Laptop::operator=(Laptop const& other) {
	if (this != &other) {
		this->erase();
		this->copy(other);
	}

	return *this;
}

Laptop::Laptop(Laptop&& other) {
	this->copy(other);

	other.brand = nullptr;
	other.model = nullptr;
	other.price = 0;
	other.screenSize = 0;
	other.clockSpeed = 0;
	other.casheSize = 0;
	other.coreNums = 0;
	other.RAMSize = 0; 
	other.batteryCapacity = 0;
}

Laptop& Laptop::operator=(Laptop&& other) {
	if (this != &other) {
		this->erase();
		this->copy(other);

		other.brand = nullptr;
		other.model = nullptr;
		other.price = 0;
		other.screenSize = 0;
		other.clockSpeed = 0;
		other.casheSize = 0;
		other.coreNums = 0;
		other.RAMSize = 0;
		other.batteryCapacity = 0;
	}

	return *this;
}

bool Laptop::operator<(Laptop const& other) const {
	bool result;
	return result = (this->screenSize < other.screenSize) ? true : false;
}

bool Laptop::operator>(Laptop const& other) const {
	bool result;
	return result = (this->screenSize > other.screenSize) ? true : false;
}

bool Laptop::operator==(Laptop const& other) const {
	bool result;
	return result = (this->screenSize == other.screenSize) ? true : false;
}

bool Laptop::operator!=(Laptop const& other) const {
	bool result;
	return result = (this->screenSize != other.screenSize) ? true : false;
}

void Laptop::print() {
	std::cout << "Laptop: " << std::endl;
	std::cout << "Brand: " << this->brand << std::endl;
	std::cout << "Model: " << this->model << std::endl;
	std::cout << "Price: " << this->price << std::endl;
	std::cout << "Screen size: " << this->screenSize << " inches" << std::endl;
	std::cout << "Processor:" << std::endl;
	std::cout << " Clock speed: " << this->clockSpeed << std::endl;
	std::cout << " Number of cores: " << this->coreNums << std::endl;
	std::cout << " Cashe size: " << this->casheSize << std::endl;
	std::cout << "RAM: " << this->RAMSize << std::endl;
	std::cout << "Battery capacity: " << this->batteryCapacity << std::endl;

	std::cout << std::endl;
}

void Laptop::updateProcessor() {
	std::cout << "Enter new clock speed: ";
	double newClockSpeed;
	std::cin >> newClockSpeed;
	this->clockSpeed = newClockSpeed;

	std::cout << "Enter new cashe size: ";
	unsigned int newCasheSize;
	std::cin >> newCasheSize;
	this->casheSize = newCasheSize;
	std::cout << std::endl;

	std::cout << "Enter new number of cores: ";
	unsigned newCoresNum;
	std::cin >> newCoresNum;
	this->coreNums = newCoresNum;
	std::cout << std::endl;

	std::cout << "New clock speed: " << this->clockSpeed << std::endl;
	std::cout << "New cashe size: " << this->casheSize << std::endl;
	std::cout << "New number of cores: " << this->coreNums << std::endl;
}

void Laptop::upgradeRAM() {
	std::cout << "Enter new size: ";
	unsigned int newSize;
	std::cin >> newSize;

	RAMSize = newSize;
	std::cout << "RAM changed!\n" << "New RAM size: " << this->RAMSize << std::endl;
}
