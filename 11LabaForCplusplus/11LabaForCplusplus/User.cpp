#include "User.h"
#include "Admin.h"
#include "Cook.h"
#include "Waiter.h"
#include "Guest.h"
#include <iostream>

User::User(const std::string& role, const std::string& firstName, const std::string& lastName)
    : role(role), firstName(firstName), lastName(lastName) {}

std::string User::getRole() const {
    return role;
}

std::shared_ptr<User> User::login(DataStorage& dataStorage) {
    std::string login, password;
    std::cout << "Login: ";
    std::cin >> login;
    std::cout << "Password: ";
    std::cin >> password;

    // Пример простой проверки
    if (dataStorage.validateAdmin(login, password)) {
        return std::make_shared<Admin>(dataStorage.getAdminName(login), "", "");
    }
    else if (dataStorage.validateCook(login, password)) {
        return std::make_shared<Cook>(dataStorage.getCookName(login), "", "");
    }
    else if (dataStorage.validateWaiter(login, password)) {
        return std::make_shared<Waiter>(dataStorage.getWaiterName(login), "", "");
    }
    else {
        return std::make_shared<Guest>(login, "", "");
    }
    return nullptr;
}
