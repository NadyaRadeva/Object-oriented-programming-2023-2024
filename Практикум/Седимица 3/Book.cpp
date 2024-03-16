#include "Book.h"
#include<cstring>
#include<iostream>

Book::Book(const char* _title, const Author& _authorBook, const char* _genre, unsigned int _year) {
    strcpy_s(this->title, _title);
    this->authorBook = _authorBook;
    strcpy_s(this->genre, _genre);
    this->year = _year;
}

const char* Book::getTitle() const {
    return this->title;
}

Author Book::getAuthor() const {
    return this->authorBook;
}

const char* Book::getGenre() const {
    return this->genre;
}

unsigned int Book::getYear() const {
    return this->year;
}

void Book::setTitle(const char* _title) {
    strcpy_s(this->title, _title);
}

void Book::setAuthorName(const Author& a) {
    this->authorBook = a;
}

void Book::setGenre(const char* _genre) {
    strcpy_s(this->genre, _genre);
}

void Book::setYear(unsigned int _year) {
    this->year = _year;
}

void Book::showBookDetails() const {
    std::cout << "Title: ";
    getTitle();
    std::cout << ", Author: ";
    getAuthor();
    std::cout << ", Genre: ";
    getGenre();
    std::cout << ", Year of publication: ";
    getYear();
    std::cout << std::endl;
}
