#include "Book.h"
#include <cstring>
#include <iostream>

void Book::copy(Book const& other) {
    char* newTitle = nullptr;
    if (other.title) {
        newTitle = new char[strlen(other.title) + 1];
        strcpy_s(newTitle, strlen(other.title) + 1, other.title);
    }

    Author* newAuthor = nullptr;
    if (other.author) {
        newAuthor = new Author(*(other.author)); // Assuming Author has a copy constructor
    }

    char* newGenre = nullptr;
    if (other.genre) {
        newGenre = new char[strlen(other.genre) + 1];
        strcpy_s(newGenre, strlen(other.genre) + 1, other.genre);
    }

    this->erase();

    this->title = newTitle;
    this->author = newAuthor;
    this->genre = newGenre;
    this->publicationYear = other.publicationYear;
}

void Book::erase() {
    delete[] this->title;
    delete this->author;
    delete[] this->genre;
}

Book::Book(char* _title, Author* _author, char* _genre, unsigned int _publicationYear)
    : title(nullptr), author(nullptr), genre(nullptr), publicationYear(_publicationYear) {
    this->setTitle(_title);
    this->setAuthor(_author);
    this->setGenre(_genre);
}

Book& Book::operator=(Book const& other) {
    if (this != &other) {
        this->erase();
        this->copy(other);
    }
    return *this;
}

Book::Book(Book&& other)
    : title(other.title), author(other.author), genre(other.genre), publicationYear(other.publicationYear) {
    other.title = nullptr;
    other.author = nullptr;
    other.genre = nullptr;
    other.publicationYear = 0;
}

Book& Book::operator=(Book&& other) {
    if (this != &other) {
        this->erase();
        this->title = other.title;
        this->author = other.author;
        this->genre = other.genre;
        this->publicationYear = other.publicationYear;

        other.title = nullptr;
        other.author = nullptr;
        other.genre = nullptr;
        other.publicationYear = 0;
    }
    return *this;
}

Book::~Book() {
    this->erase();
}

char* Book::getTitle() const {
    return this->title;
}

Author* Book::getAuthor() const {
    return this->author;
}

char* Book::getGenre() const {
    return this->genre;
}

unsigned int Book::getPublicationYear() const {
    return this->publicationYear;
}

void Book::setTitle(const char* _title) {
    delete[] this->title;
    if (_title) {
        this->title = new char[strlen(_title) + 1];
        strcpy_s(this->title, strlen(_title) + 1, _title);
    }
    else {
        this->title = nullptr;
    }
}

void Book::setAuthor(Author* a) {
    delete this->author;
    if (a) {
        this->author = new Author(*a);
    }
    else {
        this->author = nullptr;
    }
}

void Book::setGenre(const char* _genre) {
    delete[] this->genre;
    if (_genre) {
        this->genre = new char[strlen(_genre) + 1];
        strcpy_s(this->genre, strlen(_genre) + 1, _genre);
    }
    else {
        this->genre = nullptr;
    }
}

void Book::setPublicationYear(const unsigned int _publicationYear) {
    this->publicationYear = _publicationYear;
}

void Book::showBookDetails() const {
    std::cout << "Title: " << getTitle() << ", Author: ";
    if (getAuthor())
        std::cout << getAuthor()->getName();
    else
        std::cout << "Unknown";
    std::cout << ", Genre: " << getGenre() << ", Year of publication: " << getPublicationYear() << std::endl;
}
