#include "Cook.h"
#include <iostream>

Cook::Cook(const std::string& firstName, const std::string& lastName, const std::string& middleName)
    : User("cook", firstName, lastName) {}

void Cook::manageOrders(DataStorage& dataStorage) {
    int choice;
    while (true) {
        std::cout << "Cook Menu:\n";
        std::cout << "1. View Orders\n";
        std::cout << "2. Start Order Preparation\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            dataStorage.displayOrders();
            break;
        case 2:
            dataStorage.startOrderPreparation();
            break;
        case 3:
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
