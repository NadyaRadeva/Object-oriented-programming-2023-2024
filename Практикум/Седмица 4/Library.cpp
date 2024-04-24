#include "Library.h"
#include <iostream>
#include <cstring>

Library::Library(Book* _books, unsigned int _currentNumOfBooks, unsigned int _capacity)
    : books(_books), currentNumOfBooks(_currentNumOfBooks), capacity(_capacity) {}

Library::Library(const Library& other) {
    this->copy(other);
}

Library& Library::operator=(const Library& other) {
    if (this != &other) {
        this->erase();
        this->copy(other);
    }
    return *this;
}

Library::Library(Library&& other)
    : books(other.books), currentNumOfBooks(other.currentNumOfBooks), capacity(other.capacity) {
    other.books = nullptr;
    other.currentNumOfBooks = 0;
    other.capacity = 0;
}

Library& Library::operator=(Library&& other) {
    if (this != &other) {
        this->erase();
        this->books = other.books;
        this->currentNumOfBooks = other.currentNumOfBooks;
        this->capacity = other.capacity;
        other.books = nullptr;
        other.currentNumOfBooks = 0;
        other.capacity = 0;
    }
    return *this;
}

Library::~Library() {
    this->erase();
}

bool Library::addBook(Book* b) {
    if (currentNumOfBooks == capacity) {
        *this = this->resizeLibrary(2);
    }

    for (unsigned int i = 0; i < capacity; ++i) {
        if (books[i].getTitle()[0] == '\0') {
            books[i] = *b;
            currentNumOfBooks++;
            return true;
        }
    }
    return false;
}

void Library::searchByTitle(const char* _title) {
    for (unsigned int i = 0; i < currentNumOfBooks; ++i) {
        if (strcmp(books[i].getTitle(), _title) == 0) {
            books[i].showBookDetails();
            return;
        }
    }
    std::cout << "The book was not found!" << std::endl;
}

void Library::searchByAuthor(const Author& _author) {
    unsigned int result = 0;

    for (unsigned int i = 0; i < currentNumOfBooks; ++i) {
        if (strcmp(books[i].getAuthor()->getName(), _author.getName()) == 0) {
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

    for (unsigned int i = 0; i < currentNumOfBooks; ++i) {
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

    for (unsigned int i = 0; i < currentNumOfBooks; ++i) {
        if (books[i].getPublicationYear() == _year) {
            books[i].showBookDetails();
            result++;
        }
    }

    if (result == 0) {
        std::cout << "There aren't any books published in " << _year << "!" << std::endl;
    }
}

Library Library::resizeLibrary(unsigned int coeff) {
    unsigned int newCapacity = capacity * coeff;
    Book* newBooks = new Book[newCapacity];

    for (unsigned int i = 0; i < currentNumOfBooks; ++i) {
        newBooks[i] = books[i];
    }

    delete[] books;

    books = newBooks;
    capacity = newCapacity;

    return *this;
}

void Library::copy(const Library& other) {
    this->currentNumOfBooks = other.currentNumOfBooks;
    this->capacity = other.capacity;
    this->books = new Book[capacity];
    for (unsigned int i = 0; i < other.currentNumOfBooks; ++i) {
        this->books[i] = other.books[i];
    }
}

void Library::erase() {
    delete[] this->books;
    this->books = nullptr;
    this->currentNumOfBooks = 0;
    this->capacity = 0;
}
