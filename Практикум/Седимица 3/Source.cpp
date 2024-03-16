#include "Library.h"
#include "Author.h"
#include "Book.h"

#include<iostream>

int main() {
    Author author1("Matt Haig");

    Book book1("The Midnight Library", author1, "science fiction", 2020);
    Book book2("How To Stop Time", author1, "science fiction", 2017);

    Book booksArray[] = { book1, book2 };

    Library library(booksArray);

    Author author2("Ruta Sepetys");
  
    Book book3("Salt to the sea", author2, "historical fiction", 2016);
    library.addBook(book3);

    std::cout << "Searching for books by title:\n";
    library.searchByTitle("The Midnight Library");

    std::cout << "\nSearching for books by author:\n";
    library.searchByAuthor(author1);

    std::cout << "\nSearching for books by genre:\n";
    library.searchByGenre("historical fiction");

    std::cout << "\nSearching for books by year:\n";
    library.searchByYear(2021);

    return 0;
}
