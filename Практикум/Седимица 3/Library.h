#ifndef _LIBRARY_H
#include "Book.h"
#include "Author.h"

const unsigned int MAX_BOOKS = 50;

class Library {
private:
	Book books[MAX_BOOKS];

public:
	Library(Book _books[MAX_BOOKS]);

	bool addBook(Book& b);
	void searchByTitle(const char* _title);
	void searchByAuthor(const Author& _author);
	void searchByGenre(const char* _genre);
	void searchByYear(const unsigned int _year);
};

#endif // !_LIBRARY_H
