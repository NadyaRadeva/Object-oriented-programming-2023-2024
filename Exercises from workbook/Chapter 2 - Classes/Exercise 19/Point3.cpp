#include "Point3.h"

Point3::Point3() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Point3::Point3(int _x, int _y, int _z) {
	this->x = _x;
	this->y = _y;
	this->z = _z;
}

Point3::Point3(Point3 const& other) {
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}

Point3 Point3::operator=(Point3 const& other) {
	if (this != &other) {
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	}

	return *this;
}

int Point3::getX() const {
	return this->x;
}

int Point3::getY() const {
	return this->y;
}

int Point3::getZ() const {
	return this->z;
}

void Point3::setX(int _x) {
	this->x = _x;
}

void Point3::setY(int _y) {
	this->y = _y;
}

void Point3::setZ(int _z) {
	this->z = _z;
}
