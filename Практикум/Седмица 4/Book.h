#ifndef _BOOK_H
#include "Author.h"

class Book {
private:
	char* title;
	Author* author;
	char* genre;
	unsigned int publicationYear;

	void copy(Book const& other);
	void erase();

public:
	Book(char* _title, Author* author, char* _genre, unsigned int _publicationYear);

	Book(Book const& other);
	Book& operator=(Book const& other);
	Book(Book&& other);
	Book& operator=(Book&& other);
	~Book();

	char* getTitle() const;
	Author* getAuthor() const;
	char* getGenre() const;
	unsigned int getPublicationYear() const;

	void setTitle(const char* _title);
	void setAuthor(Author* a);
	void setGenre(const char* _genre);
	void setPublicationYear(const unsigned int _publicationYear);

	void showBookDetails() const;
};

#endif // !_BOOK_H
