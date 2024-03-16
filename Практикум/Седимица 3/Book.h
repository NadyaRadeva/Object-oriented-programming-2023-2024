#ifndef _BOOK_H
#include "Author.h"

const unsigned int MAX_TITLE_LEN = 31;
const unsigned int MAX_GENRE_LEN = 31;

class Book {
private:
	char title[MAX_TITLE_LEN];
	Author authorBook;
	char genre[MAX_GENRE_LEN];
	unsigned int year;

public:
	Book(const char* _title, const Author& _authorBook, const char* _genre, unsigned int _year);

	const char* getTitle() const;
	Author getAuthor() const;
	const char* getGenre() const;
	unsigned int getYear() const;

	void setTitle(const char* _title);
	void setAuthorName(const Author& a);
	void setGenre(const char* _genre);
	void setYear(const unsigned int _year);

	void showBookDetails() const;
};

#endif // !_BOOK_H
