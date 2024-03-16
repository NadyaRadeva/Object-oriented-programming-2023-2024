#ifndef _AUTHOR_H

const unsigned int MAX_NAME_LEN = 31;

class Author {
private:
	char name[MAX_NAME_LEN];

public:
	Author();
	Author(char* _name);

	const char* getName() const;
};

#endif // !_AUTHOR_H
