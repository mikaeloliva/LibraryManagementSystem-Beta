
// ------------ Catolog.cpp File ------------ //
//
//
// -------- Catolog.cpp File ----------- //



#include "Catalog.h"
#include <iostream>

std::vector<Book> Catalog::searchByTitle(const std::vector<Book>& books, const std::string& title) {
    std::vector<Book> results;
    for (const auto& book : books) {
        if (book.getTitle().find(title) != std::string::npos) {
            results.push_back(book);
        }
    }
    return results;
}

std::vector<Book> Catalog::searchByAuthor(const std::vector<Book>& books, const std::string& author) {
    std::vector<Book> results;
    for (const auto& book : books) {
        if (book.getAuthor().find(author) != std::string::npos) {
            results.push_back(book);
        }
    }
    return results;
}

void Catalog::printResults(const std::vector<Book>& results) {
    if (results.empty()) {
        std::cout << "No matching books found.\n";
        return;
    }

    std::cout << "Search Results:\n";
    for (const auto& book : results) {
        std::cout << "- " << book.getTitle() << " by " << book.getAuthor()
            << " [" << (book.available() ? "Available" : "Borrowed") << "]\n";
    }
}
