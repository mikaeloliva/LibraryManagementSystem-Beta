// -------- Transaction.cpp ----------- //


#include "Transaction.h"
#include <iostream>
#include <iomanip>

Transaction::Transaction(std::string i, int uid, std::string act)
    : isbn(i), userId(uid), action(act), timestamp(std::time(nullptr)) {
}

void Transaction::print() const {
    tm timeInfo;
    localtime_s(&timeInfo, &timestamp);
    std::cout << "User " << userId << " " << action << " book ISBN " << isbn
        << " at " << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S") << std::endl;
}
