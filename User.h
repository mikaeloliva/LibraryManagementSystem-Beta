#pragma once
#include <string>
#include <vector>
#include "Book.h"

class User {
private:
    int userId;
    std::string name;
    std::vector<Book*> borrowedBooks;  // Store pointers to original books

public:
    User(int id, std::string n);
    std::string getName() const;
    int getId() const;
    void borrowBook(Book* book);               // Accept pointer
    void returnBook(std::string isbn);         // Match by ISBN
    void listBorrowedBooks() const;
};
