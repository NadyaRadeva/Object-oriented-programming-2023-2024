#include "Fact.h"

Fact::Fact(int a) {
	this->x = a;
}

unsigned int Fact::value() const {
	int y = 1;
	for (size_t i = 0; i <= x; ++i) {
		y *= i;
	}
	return y;
}
