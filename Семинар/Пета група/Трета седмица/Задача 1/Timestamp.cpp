#include "Timestamp.h"
#include<iostream>

Timestamp::Timestamp() {
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
}

Timestamp::Timestamp(unsigned int _hours, unsigned int _minutes, unsigned int _seconds) {
	this->hours = _hours;
	this->minutes = _minutes;
	this->seconds = _seconds;
}

unsigned int Timestamp::getHours() const {
	return this->hours;
}

unsigned int Timestamp::getMinutes() const {
	return this->minutes;
}

unsigned int Timestamp::getSeconds() const {
	return this->seconds;
}

void Timestamp::setHours(unsigned int _hours) {
	this->hours = _hours;
}

void Timestamp::setMinutes(unsigned int _minutes) {
	this->minutes = _minutes;
}

void Timestamp::setSeconds(unsigned int _seconds) {
	this->seconds = _seconds;
}

void Timestamp::printTime() {
	if (getHours() < 10) {
		std::cout << "0" << getHours() << ":";
	}
	else {
		std::cout << getHours() << ":";
	}

	if (getMinutes() < 10) {
		std::cout << "0" << getMinutes() << ":";
	}
	else {
		std::cout << getMinutes() << ":";
	}

	if (getSeconds() < 10) {
		std::cout << "0" << getSeconds() << ":" << std::endl;
	}
	else {
		std::cout << getSeconds() << ":" << std::endl;
	}
}

unsigned int Timestamp::convertToSeconds() {
	return getHours() * 60 * 60 + getMinutes() * 60 + getSeconds();
}

Timestamp* Timestamp::addTimestamps(Timestamp& other) {
	unsigned int totalSeconds = convertToSeconds() + other.convertToSeconds();

	unsigned int hours = totalSeconds / 3600;
	unsigned int minutes = (totalSeconds % 3600) / 60;
	unsigned int seconds = totalSeconds % 60;

	Timestamp* sumTimestamp = new Timestamp(hours, minutes, seconds);

	return sumTimestamp;
}
