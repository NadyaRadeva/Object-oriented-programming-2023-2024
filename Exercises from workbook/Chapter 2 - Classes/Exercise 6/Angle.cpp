#include "Angle.h"
#include<cmath>

const double DEG_TO_RAD = 3.1415;

void Angle::setValue(double deg) {
	this->degree = deg;
}

double Angle::getSin() const {
	return sin(DEG_TO_RAD * this -> degree);
}

double Angle::getCos() const {
	return cos(DEG_TO_RAD * this -> degree);
}

double Angle::getTan() const {
	return tan(DEG_TO_RAD * this->degree);
}
