// -------------- Library.cpp file ------------ //


#include "Library.h"
#include <iostream>

void Library::addBook(const Book& book) {
    books.push_back(book);
    std::cout << "Added book: " << book.getTitle() << std::endl;
}

void Library::addUser(User* user) {
    users.push_back(user);
    std::cout << "Registered user: " << user->getName() << std::endl;
}


void Library::borrowBook(int userId, std::string isbn) {
    for (auto& book : books) {
        if (book.getISBN() == isbn && book.available()) {
            for (auto& user : users) {
                if (user->getId() == userId) {
                    user->borrowBook(&book);
                    return;
                }
            }
        }
    }
    std::cout << "Borrow failed: Book not available or user not found.\n";
}


void Library::returnBook(int userId, std::string isbn) {
    for (auto& book : books) {
        if (book.getISBN() == isbn) {
            for (auto& user : users) {
                if (user->getId() == userId) {
                    user->returnBook(isbn);
                    return;
                }
            }
        }
    }
    std::cout << "Return failed: Book or user not found.\n";
}


void Library::listAllBooks() const {
    std::cout << "Library Books:\n";
    for (const auto& book : books) {
        std::cout << "- " << book.getTitle() << " by " << book.getAuthor()
            << " [" << (book.available() ? "Available" : "Borrowed") << "]\n";
    }
}
