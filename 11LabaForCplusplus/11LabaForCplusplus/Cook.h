#pragma once
#include "User.h"
#include "DataStorage.h"

class Cook : public User {
public:
    Cook(const std::string& firstName, const std::string& lastName, const std::string& middleName);
    void manageOrders(DataStorage& dataStorage);
};
