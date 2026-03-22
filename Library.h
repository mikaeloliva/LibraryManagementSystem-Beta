#pragma once
#include <vector>
#include <string>
#include "Book.h"
#include "User.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<User*> users;

public:
    void addBook(const Book& book);
    void addUser(User* user);
    void borrowBook(int userId, std::string isbn);
    void returnBook(int userId, std::string isbn);
    void listAllBooks() const;
};
