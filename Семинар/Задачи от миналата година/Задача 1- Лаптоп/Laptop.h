#ifndef _LAPTOP_H

class Laptop {
private:
	char* brand;
	char* model;
	double price, screenSize;
	double clockSpeed;
	unsigned int casheSize, coreNums, RAMSize, batteryCapacity;

	void copy(Laptop const& other);
	void erase() const;

public:
	Laptop();
	Laptop(char* _brand, char* _model, double _price, double _screenSize, double _clockSpeed, unsigned int _casheSize, unsigned int _coreNums, unsigned int _RAMSize, unsigned int _batteryCapacity);
	~Laptop();
	Laptop(Laptop const& other);
	Laptop operator=(Laptop const& other);

	Laptop(Laptop&& other);
	Laptop& operator=(Laptop&& other);

	bool operator<(Laptop const& other) const;
	bool operator>(Laptop const& other) const;
	bool operator==(Laptop const& other) const;
	bool operator!=(Laptop const& other) const;

	void print();
	void updateProcessor();
	void upgradeRAM();
};

#endif // !_LAPTOP_H
