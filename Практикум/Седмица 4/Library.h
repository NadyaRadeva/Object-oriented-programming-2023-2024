#ifndef _LIBRARY_H
#include "Book.h"

class Library {
private:
	Book* books;
	unsigned int currentNumOfBooks;

	Library resizeLibrary(unsigned int coeff);
	void copy(Library const& other);
	void erase();

public:
	Library(Book* books, unsigned int currentNumOfBooks);
	Library(Library const& other);
	Library& operator=(Library const& other);
	Library(Library&& other);
	Library& operator=(Library&& other);

	bool addBook(Book* b);
	void searchByTitle(const char* _title);
	void searchByAuthor(Author* _author);
	void searchByGenre(const char* _genre);
	void searchByYear(const unsigned int _year);
};

#endif // !_LIBRARY_H
