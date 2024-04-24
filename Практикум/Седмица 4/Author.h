#ifndef _AUTHOR_H

class Author {
private:
	char* name;

	void copy(Author const& other);
	void erase();

public:
	Author();
	Author(char* _name);
	Author(Author const& other);
	Author& operator=(Author const& other);
	Author(Author&& other);
	Author& operator=(Author&& other);
	~Author();

	char* getName() const;

};

#endif // !_AUTHOR_H
