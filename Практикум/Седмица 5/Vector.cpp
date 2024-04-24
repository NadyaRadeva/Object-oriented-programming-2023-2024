#include "Vector.h"
#include<iostream>

void Vector::copy(Vector const& other){
	this->sizeVec = other.sizeVec;
	this->vec = new int[sizeVec];
	for (size_t i = 0; i < sizeVec; ++i) {
		this->vec[i] = other.vec[i];
	}
}

void Vector::erase(){
	delete[] this->vec;
}

void Vector::resizeVec() {
	int* newVec = new int[this->sizeVec + 1];
	for (size_t i = 0; i < this->sizeVec; ++i) {
		newVec[i] = this->vec[i];
	}
	delete[] this->vec;
	this->vec = newVec;
	this->sizeVec++;
}

Vector::Vector() {
	this->vec = nullptr;
	this->sizeVec = 0;
}

Vector::Vector(int* _vec, unsigned int _sizeVec) {
	this->sizeVec = _sizeVec;
	this->vec = new int[sizeVec];
	for (size_t i = 0; i < sizeVec; ++i) {
		this->vec[i] = _vec[i];
	}
}

Vector::Vector(Vector const& other) {
	this->copy(other);
}

Vector Vector::operator=(Vector const& other) {
	if (this != &other) {
		this->erase();
		this->copy(other);
	}

	return *this;
}

Vector::Vector(Vector&& other) {
	this->copy(other);

	other.sizeVec = 0;
	other.vec = nullptr;
}

Vector& Vector::operator=(Vector&& other){
	if (this != &other) {
		this->erase();
		this->copy(other);

		other.sizeVec = 0;
		other.vec = nullptr;
	}

	return *this;
}

Vector::~Vector() {
	this->erase();
}

unsigned int Vector::getSize() const {
	return this->sizeVec;
}

void Vector::setSize(unsigned int _size) {
	this->sizeVec = _size;
}

void Vector::pushBack(int value) {
	resizeVec();
	this->vec[this->sizeVec - 1] = value;
}

void Vector::popBack() {
	if (this->sizeVec > 0) {
		this->sizeVec--;
		int* newVec = new int[this->sizeVec];
		for (size_t i = 0; i < this->sizeVec; ++i) {
			newVec[i] = this->vec[i];
		}
		delete[] this->vec;
		this->vec = newVec;
	}
}

int Vector::at(unsigned int index) {
	if (index < this->sizeVec) {
		return this->vec[index];
	}
	else {
		return -1;
	}
}

void Vector::insertAt(unsigned int index, int value) {
	if (index <= this->sizeVec) {
		resizeVec();

		for (size_t i = this->sizeVec - 1; i > index; --i) {
			this->vec[i] = this->vec[i - 1];
		}

		this->vec[index] = value;
	}
}

void Vector::deleteAt(unsigned int index) {
	if (index < this->sizeVec) {
		this->vec[index] = 0;

		for (size_t i = index; i < this->sizeVec - 1; ++i) {
			this->vec[i] = this->vec[i + 1];
		}

		this->sizeVec--;
	}
}

void Vector::sort() {
	int min;
	unsigned int minIndex;

	for (size_t i = 0; i < this->sizeVec; ++i) {
		minIndex = i;
		min = this->vec[minIndex];
		for (size_t j = i + 1; j < this->sizeVec; ++j) {
			if (this->vec[j] < min) {
				minIndex = j;
				min = this->vec[minIndex];
			}
		}

		this->vec[minIndex] = this->vec[i];
		this->vec[i] = min;
	}
}

void Vector::concat(Vector const& other) {
	Vector vecConcat;

	vecConcat.sizeVec = this->sizeVec + other.sizeVec;
	vecConcat.vec = new int[vecConcat.sizeVec];

	for (size_t i = 0; i < this->sizeVec; ++i) {
		vecConcat.vec[i] = this->vec[i];
	}

	for (size_t i = 0; i < other.sizeVec; ++i) {
		vecConcat.vec[this->sizeVec + i] = other.vec[i];
	}

	delete[] this->vec;
	this->vec = vecConcat.vec;
	this->sizeVec = vecConcat.sizeVec;
}

Vector* Vector::slice(unsigned int start, unsigned int end) {
	if (start >= end || start >= this->sizeVec || end > this->sizeVec) {
		return nullptr;
	}

	unsigned int newSize = end - start;

	Vector* newVec = new Vector();

	newVec->vec = new int[newSize];
	newVec->sizeVec = newSize;

	for (unsigned int i = start, j = 0; i < end; ++i, ++j) {
		newVec->vec[j] = this->vec[i];
	}

	return newVec;
}

void Vector::reverse() {
	Vector revVec;

	revVec.sizeVec = this->sizeVec;
	revVec.vec = new int[revVec.sizeVec];

	for (size_t i = revVec.sizeVec - 1, j = 0; i >= 0 && j < revVec.sizeVec; --i, ++j) {
		revVec.vec[j] = this->vec[i];
	}

	delete[] this->vec;
	this->vec = revVec.vec;
	this->sizeVec = revVec.sizeVec;
}
