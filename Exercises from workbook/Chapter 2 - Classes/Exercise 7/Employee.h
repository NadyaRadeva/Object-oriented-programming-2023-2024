#ifndef _EMPLOYEE_H

class Employee {
private:
	struct name {
		char first[16];
		char last[16];
	};

	struct work {
		double hours;
		double wage;
	};

public:
	void read();
	void print() const;
};

#endif // !_EMPLOYEE_H
