// ============ LibraryManagement System ============
// ============ Michael Alexander Oliva =============
// ============ 03-21-2026 ================

// ========== Include Library Files =========
#include <iostream>
#include <limits>
#include "Book.h"             /// Book Class
#include "User.h"             /// User Class
#include "Library.h"          /// Library Class
#include "Librarian.h"        /// Librarian Class
#include "Transaction.h"      /// Transaction Class
#include "Catalog.h"          /// Catalog Class
#include "Notification.h"     /// Notification Classa
#include "ReportGenerator.h"  /// ReportGenerator Class

// ===== Main Program Entry Point =====
int main() {
    // ===== Setup: Library and Admin =====
    Library lib;
    Librarian admin;

    // ===== Book Class: Sample Books =====
    Book b1("C++ Primer", "Lippman", "12345");
    Book b2("Effective C++", "Scott Meyers", "67890");
    Book b3("The C++ Programming Language", "Bjarne Stroustrup", "99999");

    // ===== User Class: Sample Users =====
    User u1(1, "Michael User 1");
    User u2(2, "Alexa User 2");

    // ===== Librarian Class: Add Books and Users =====
    admin.addBookToLibrary(lib, b1);
    admin.addBookToLibrary(lib, b2);
    admin.addBookToLibrary(lib, b3);
    admin.registerUser(lib, &u1);
    admin.registerUser(lib, &u2);


    // ===== Menu System =====
    int choice;
    do {
        std::cout << "\n===== Library Menu =====\n";
        std::cout << "1. List all books\n";
        std::cout << "2. Borrow a book\n";
        std::cout << "3. Return a book\n";
        std::cout << "4. Search books by title\n";
        std::cout << "5. Search books by author\n";
        std::cout << "6. Generate user report\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            // ===== Library Class: List All Books =====
            lib.listAllBooks();
            break;
        case 2: {
            // ===== Transaction + Notification: Borrow Book =====
            int userId;
            std::string isbn;
            std::cout << "Enter user ID: ";
            std::cin >> userId;
            std::cout << "Enter book ISBN to borrow: ";
            std::cin >> isbn;
            lib.borrowBook(userId, isbn);
            Notification::send("Book borrowed successfully.");
            Transaction t(isbn, userId, "Borrow");
            t.print();
            break;
        }
        case 3: {
            // ===== Transaction + Notification: Return Book =====
            int userId;
            std::string isbn;
            std::cout << "Enter user ID: ";
            std::cin >> userId;
            std::cout << "Enter book ISBN to return: ";
            std::cin >> isbn;
            lib.returnBook(userId, isbn);
            Notification::send("Book returned successfully.");
            Transaction t(isbn, userId, "Return");
            t.print();
            break;
        }
        case 4: {
            // ===== Catalog Class: Search by Title =====
            std::string title;
            std::cout << "Enter title keyword: ";
            std::getline(std::cin, title);
            auto results = Catalog::searchByTitle({ b1, b2, b3 }, title);
            Catalog::printResults(results);
            break;
        }
        case 5: {
            // ===== Catalog Class: Search by Author =====
            std::string author;
            std::cout << "Enter author keyword: ";
            std::getline(std::cin, author);
            auto results = Catalog::searchByAuthor({ b1, b2, b3 }, author);
            Catalog::printResults(results);
            break;
        }
        case 6:
            // ===== ReportGenerator Class: User Reports =====
            ReportGenerator::generateUserReport(&u1);
            ReportGenerator::generateUserReport(&u2);
            break;
        case 0:
            std::cout << "Exiting Library System. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
