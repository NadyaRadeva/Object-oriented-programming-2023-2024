#include "Library.h"
#include "Book.h"
#include<cstring>
#include<iostream>

Library::Library(Book _books[MAX_BOOKS]) {
    for (int i = 0; i < MAX_BOOKS; ++i) {
        books[i] = _books[i];
    }
}

bool Library::addBook(Book& b) {
    for (int i = 0; i < MAX_BOOKS; ++i) {
        if (books[i].getTitle()[0] == '\0') {
            books[i] = b;
            return true;
        }
    }
    return false;
}

void Library::searchByTitle(const char* _title) {
    for (int i = 0; i < MAX_BOOKS; ++i) {
        if (strcmp(books[i].getTitle(), _title) == 0) {
            books[i].showBookDetails();
            return;
        }
    }
    std::cout << "The book was not found!" << std::endl;
}

void Library::searchByAuthor(const Author& _author) {
    unsigned int result = 0;

    for (int i = 0; i < MAX_BOOKS; ++i) {
        if (strcmp(books[i].getAuthor().getName(), _author.getName()) == 0) {
            books[i].showBookDetails();
            result++;
        }
    }

    if (result == 0) {
        std::cout << "There aren't any books written by this author!" << std::endl;
    }
}

void Library::searchByGenre(const char* _genre) {
    unsigned int result = 0;

    for (int i = 0; i < MAX_BOOKS; ++i) {
        if (strcmp(books[i].getGenre(), _genre) == 0) {
            books[i].showBookDetails();
            result++;
        }
    }

    if (result == 0) {
        std::cout << "There aren't any books in this genre!" << std::endl;
    }
}

void Library::searchByYear(const unsigned int _year) {
    unsigned int result = 0;

    for (int i = 0; i < MAX_BOOKS; ++i) {
        if (books[i].getYear() == _year) {
            books[i].showBookDetails();
            result++;
        }
    }

    if (result == 0) {
        std::cout << "There aren't any books published in " << _year << "!" << std::endl;
    }
}
