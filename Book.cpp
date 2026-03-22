// ------------- Book.cpp File ------------ //


#include "Book.h"

Book::Book(std::string t, std::string a, std::string i)
    : title(t), author(a), isbn(i), isAvailable(true) {
}

std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getISBN() const { return isbn; }
bool Book::available() const { return isAvailable; }

void Book::borrow() { isAvailable = false; }
void Book::returnBook() { isAvailable = true; }
