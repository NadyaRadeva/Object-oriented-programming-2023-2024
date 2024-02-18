#include "Point.h"

Point::Point(double _x, double _y) {
	this->x = _x;
	this->y = _y;
}

double Point::xcoord() const {
	return this->x;
}

double Point::ycoord() const {
	return this->y;
}
