

#pragma once
#pragma once
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool isAvailable;

public:
    Book(std::string t, std::string a, std::string i);
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;
    bool available() const;
    void borrow();
    void returnBook();
};
