#include "Library.h"
#include <iostream>

int main() {
    Author author1("Cassandra Clare");
    Author author2("Matt Haig");

    Book book1("Clockwork Angel", &author1, "historical fantasy", 2011);
    Book book2("The Midnight Library", &author2, "science fiction", 2020);

    Book books[2];
    Library library(books, 0, 2);
  
    library.addBook(&book1);
    library.addBook(&book2);

    Book book3("Salt to the sea", author2, "historical fiction", 2016);
    library.addBook(&book3);

    library.searchByTitle("Clockwork Angel");

    std::cout << "Searching books by Author: Author1" << std::endl;
    library.searchByAuthor(author1);

    std::cout << "Searching books by Genre: Genre2" << std::endl;
    library.searchByGenre("Genre2");

    std::cout << "Searching books published in 2010" << std::endl;
    library.searchByYear(2010);

    return 0;
}
