#pragma once
#include "User.h"
#include "Menu.h"
#include "Order.h"
#include "DataStorage.h"

class Guest : public User {
public:
    Guest(const std::string& firstName, const std::string& lastName, const std::string& middleName);
    void makeOrder(DataStorage& dataStorage);
};
