// ---------- ReportGenerator ------------- //


#include "ReportGenerator.h"
#include <iostream>

void ReportGenerator::generateUserReport(User* user) {
    std::cout << "\n===== User Report =====\n";
    std::cout << "User ID: " << user->getId() << "\n";
    std::cout << "Name: " << user->getName() << "\n";
    user->listBorrowedBooks();
}
