#include <iostream>
#include <string>
#include "Admin.h"
#include "Cook.h"
#include "Waiter.h"
#include "Guest.h"
#include "Utils.h"
#include "DataStorage.h"

int main() {
    DataStorage dataStorage;
    dataStorage.loadAllData();

    int userType;
    std::string login, password;

    std::cout << "Welcome to the Restaurant Management System!\n";
    std::cout << "1. Admin\n";
    std::cout << "2. Cook\n";
    std::cout << "3. Waiter\n";
    std::cout << "4. Guest\n";
    std::cout << "Enter your role: ";
    std::cin >> userType;

    if (userType != 4) { // Guest does not need to log in
        std::cout << "Enter login: ";
        std::cin >> login;
        std::cout << "Enter password: ";
        std::cin >> password;
    }

    switch (userType) {
    case 1:
        if (dataStorage.validateAdmin(login, password)) {
            Admin admin(dataStorage.getAdminName(login), "", "");
            admin.manageSystem(dataStorage);
        }
        else {
            std::cout << "Invalid login or password for Admin.\n";
        }
        break;
    case 2:
        if (dataStorage.validateCook(login, password)) {
            Cook cook(dataStorage.getCookName(login), "", "");
            cook.manageOrders(dataStorage);
        }
        else {
            std::cout << "Invalid login or password for Cook.\n";
        }
        break;
    case 3:
        if (dataStorage.validateWaiter(login, password)) {
            Waiter waiter(dataStorage.getWaiterName(login), "", "");
            waiter.serveOrders(dataStorage);
        }
        else {
            std::cout << "Invalid login or password for Waiter.\n";
        }
        break;
    case 4: {
        std::string firstName, lastName, middleName;
        std::cout << "Enter your first name: ";
        std::cin >> firstName;
        std::cout << "Enter your last name: ";
        std::cin >> lastName;
        std::cout << "Enter your middle name: ";
        std::cin >> middleName;
        Guest guest(firstName, lastName, middleName);
        guest.makeOrder(dataStorage);
        break;
    }
    default:
        std::cout << "Invalid role selected.\n";
        break;
    }

    dataStorage.saveAllData();
    return 0;
}
