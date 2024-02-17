#include "GCD.h"

GCD::GCD(int a, int b) {
	this->x = a;
	this->y = b;
}

int GCD::value() const {
	if (y == 0) {
		return x;
	}
	else {
		GCD t(y, x % y);
		return t.value();
	}
}
