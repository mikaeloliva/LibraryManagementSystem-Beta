// ----- User.cpp -------- //


#include "User.h"
#include <iostream>

User::User(int id, std::string n) : userId(id), name(n) {}

std::string User::getName() const { return name; }
int User::getId() const { return userId; }

void User::borrowBook(Book* book) {
    borrowedBooks.push_back(book);
    book->borrow(); // Mark the original book as borrowed
    std::cout << name << " borrowed: " << book->getTitle() << std::endl;
}

void User::returnBook(std::string isbn) {
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        if ((*it)->getISBN() == isbn) {
            (*it)->returnBook();  // Mark the original book as available
            std::cout << name << " returned: " << (*it)->getTitle() << std::endl;
            borrowedBooks.erase(it);
            return;
        }
    }
    std::cout << "Book with ISBN " << isbn << " not found in borrowed list.\n";
}

void User::listBorrowedBooks() const {
    std::cout << name << "'s borrowed books:\n";
    if (borrowedBooks.empty()) {
        std::cout << "(none)\n";
        return;
    }
    for (const auto& book : borrowedBooks) {
        std::cout << "- " << book->getTitle() << " by " << book->getAuthor() << std::endl;
    }
}
