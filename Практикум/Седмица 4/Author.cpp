#include "Author.h"
#include <cstring>

void Author::copy(Author const& other) {
    char* newName = nullptr;
    if (other.name) {
        newName = new char[strlen(other.name) + 1];
        strcpy_s(newName, strlen(other.name) + 1, other.name);
    }
    delete[] this->name;
    this->name = newName;
}

void Author::erase() {
    delete[] this->name;
    this->name = nullptr;
}

Author::Author() {
    this->name = nullptr;
}

Author::Author(char* _name) {
    this->name = nullptr;
    if (_name) {
        this->name = new char[strlen(_name) + 1];
        strcpy_s(this->name, strlen(_name) + 1, _name);
    }
}

Author::Author(Author const& other) {
    this->name = nullptr;
    this->copy(other);
}

Author& Author::operator=(Author const& other) {
    if (this != &other) {
        this->erase();
        this->copy(other);
    }
    return *this;
}

Author::Author(Author&& other) {
    this->name = other.name;
    other.name = nullptr;
}

Author& Author::operator=(Author&& other) {
    if (this != &other) {
        delete[] this->name;
        this->name = other.name;
        other.name = nullptr;
    }
    return *this;
}

Author::~Author() {
    this->erase();
}

char* Author::getName() const {
    return this->name;
}
