#include "Waiter.h"
#include <iostream>

Waiter::Waiter(const std::string& firstName, const std::string& lastName, const std::string& middleName)
    : User("waiter", firstName, lastName) {}

void Waiter::serveOrders(DataStorage& dataStorage) {
    int choice;
    while (true) {
        std::cout << "Waiter Menu:\n";
        std::cout << "1. View Orders\n";
        std::cout << "2. Complete Order\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            dataStorage.displayOrders();
            break;
        case 2:
            dataStorage.completeOrder();
            break;
        case 3:
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
