// ------------ Librarian.cpp File ------------ //

#include "Librarian.h"
#include <iostream>

void Librarian::addBookToLibrary(Library& lib, const Book& book) {
    lib.addBook(book);
    std::cout << "Librarian added book: " << book.getTitle() << std::endl;
}

void Librarian::registerUser(Library& lib, User* user) {
    lib.addUser(user);
}
