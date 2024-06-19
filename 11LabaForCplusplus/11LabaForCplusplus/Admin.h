#pragma once
#include "User.h"
#include "Menu.h"
#include "Product.h"
#include "DataStorage.h"

class Admin : public User {
public:
    Admin(const std::string& firstName, const std::string& lastName, const std::string& middleName);
    void manageSystem(DataStorage& dataStorage);
};
