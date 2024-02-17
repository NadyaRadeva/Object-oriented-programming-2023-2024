#include "Absolute.h"

int Absolute::abs(int number) {
	if (number >= 0) {
		return number;
	}
	else {
		return -(number);
	}
}

double Absolute::abs(double number) {
	if (number >= 0) {
		return number;
	}
	else {
		return -(number);
	}
}
