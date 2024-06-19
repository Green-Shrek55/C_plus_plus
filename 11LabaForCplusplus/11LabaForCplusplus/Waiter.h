#pragma once
#include "User.h"
#include "DataStorage.h"

class Waiter : public User {
public:
    Waiter(const std::string& firstName, const std::string& lastName, const std::string& middleName);
    void serveOrders(DataStorage& dataStorage);
};
