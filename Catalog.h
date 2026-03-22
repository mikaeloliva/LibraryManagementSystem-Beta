#pragma once
#include <vector>
#include <string>
#include "Book.h"

class Catalog {
public:
    static std::vector<Book> searchByTitle(const std::vector<Book>& books, const std::string& title);
    static std::vector<Book> searchByAuthor(const std::vector<Book>& books, const std::string& author);
    static void printResults(const std::vector<Book>& results);
};
