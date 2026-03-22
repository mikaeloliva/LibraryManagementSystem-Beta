#pragma once
#include "Library.h"
#include "Book.h"
#include "User.h"

class Librarian {
public:
    void addBookToLibrary(Library& lib, const Book& book);
    void registerUser(Library& lib, User* user);

};
