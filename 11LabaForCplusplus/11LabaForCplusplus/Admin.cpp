#include "Admin.h"
#include <iostream>

Admin::Admin(const std::string& firstName, const std::string& lastName, const std::string& middleName)
    : User("admin", firstName, lastName) {}

void Admin::manageSystem(DataStorage& dataStorage) {
    int choice;
    while (true) {
        std::cout << "Admin Menu:\n";
        std::cout << "1. Manage Menu\n";
        std::cout << "2. Manage Products\n";
        std::cout << "3. Manage Employees\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            dataStorage.manageMenu();
            break;
        case 2:
            dataStorage.manageProducts();
            break;
        case 3:
            dataStorage.manageEmployees();
            break;
        case 4:
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
