#include "Author.h"
#include<cstring>

Author::Author() {
	strcpy_s(this->name, nullptr);
}

Author::Author(char* _name) {
	strcpy_s(this->name, _name);
}

const char* Author::getName() const {
	return this->name;
}
