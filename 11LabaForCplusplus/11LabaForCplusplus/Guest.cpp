#include "Guest.h"
#include <iostream>

Guest::Guest(const std::string& firstName, const std::string& lastName, const std::string& middleName)
    : User("guest", firstName, lastName) {}

void Guest::makeOrder(DataStorage& dataStorage) {
    Order order(getRole());
    int choice;
    while (true) {
        std::cout << "Guest Menu:\n";
        std::cout << "1. View Menu\n";
        std::cout << "2. Add Item to Order\n";
        std::cout << "3. Confirm Order\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            dataStorage.displayMenu();
            break;
        case 2: {
            std::string itemName;
            std::cout << "Enter item name to add: ";
            std::cin >> itemName;
            MenuItem* item = dataStorage.findMenuItem(itemName);
            if (item) {
                order.addItem(*item);
            }
            else {
                std::cout << "Item not found.\n";
            }
            break;
        }
        case 3:
            order.confirmOrder();
            dataStorage.addOrder(order);
            std::cout << "Order confirmed.\n";
            return;
        case 4:
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
