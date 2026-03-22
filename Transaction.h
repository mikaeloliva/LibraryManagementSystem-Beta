#pragma once
#include <string>
#include <ctime>

class Transaction {
private:
    std::string isbn;
    int userId;
    std::string action; // "Borrow" or "Return"
    std::time_t timestamp;

public:
    Transaction(std::string i, int uid, std::string act);
    void print() const;
};
