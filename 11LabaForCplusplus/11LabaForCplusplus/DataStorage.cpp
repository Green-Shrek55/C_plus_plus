#include "DataStorage.h"
#include <fstream>
#include <iostream>

DataStorage::DataStorage() {}

void DataStorage::loadAllData() {
    // Загрузка данных из файлов (упрощенная версия)
    std::ifstream menuFile("menu.txt");
    if (menuFile.is_open()) {
        std::string name, description;
        int prepTime, productId;
        double price;
        while (menuFile >> name >> prepTime >> price >> description) {
            std::vector<int> productIds;
            while (menuFile >> productId) {
                productIds.push_back(productId);
            }
            menu.emplace_back(name, productIds, description, prepTime, price);
        }
        menuFile.close();
    }

    std::ifstream productsFile("products.txt");
    if (productsFile.is_open()) {
        int id;
        std::string name;
        double cost;
        while (productsFile >> id >> name >> cost) {
            products.emplace_back(id, name, cost);
        }
        productsFile.close();
    }

    std::ifstream ordersFile("orders.txt");
    if (ordersFile.is_open()) {
        std::string guestName, itemName, status;
        while (ordersFile >> guestName >> status) {
            Order order(guestName);
            MenuItem* item;
            while (ordersFile >> itemName) {
                item = findMenuItem(itemName);
                if (item) {
                    order.addItem(*item);
                }
            }
            order.updateStatus(status);
            orders.push_back(order);
        }
        ordersFile.close();
    }

    std::ifstream usersFile("users.txt");
    if (usersFile.is_open()) {
        std::string role, login, password;
        while (usersFile >> role >> login >> password) {
            if (role == "admin") {
                admins.emplace_back(login, password);
            }
            else if (role == "cook") {
                cooks.emplace_back(login, password);
            }
            else if (role == "waiter") {
                waiters.emplace_back(login, password);
            }
        }
        usersFile.close();
    }
}

void DataStorage::saveAllData() {
    // Сохранение данных в файлы (упрощенная версия)
    std::ofstream menuFile("menu.txt");
    if (menuFile.is_open()) {
        for (const auto& item : menu) {
            menuFile << item.getName() << " " << item.getPrepTime() << " " << item.getPrice() << " " << item.getDescription() << "\n";
            for (const auto& id : item.getProductIds()) {
                menuFile << id << " ";
            }
            menuFile << "\n";
        }
        menuFile.close();
    }

    std::ofstream productsFile("products.txt");
    if (productsFile.is_open()) {
        for (const auto& product : products) {
            productsFile << product.getId() << " " << product.getName() << " " << product.getCost() << "\n";
        }
        productsFile.close();
    }

    std::ofstream ordersFile("orders.txt");
    if (ordersFile.is_open()) {
        for (const auto& order : orders) {
            ordersFile << order.getStatus() << " ";
            for (const auto& item : order.getItems()) {
                ordersFile << item.getName() << " ";
            }
            ordersFile << "\n";
        }
        ordersFile.close();
    }

    std::ofstream usersFile("users.txt");
    if (usersFile.is_open()) {
        for (const auto & [login, password] : admins) {
            usersFile << "admin " << login << " " << password << "\n";
        }
        for (const auto& [login, password] : cooks) {
            usersFile << "cook " << login << " " << password << "\n";
        }
        for (const auto& [login, password] : waiters) {
            usersFile << "waiter " << login << " " << password << "\n";
        }
        usersFile.close();
    }
}

void DataStorage::displayMenu() const {
    for (const auto& item : menu) {
        item.displayItem();
    }
}

MenuItem* DataStorage::findMenuItem(const std::string& name) {
    for (auto& item : menu) {
        if (item.getName() == name) {
            return &item;
        }
    }
    return nullptr;
}

void DataStorage::addOrder(const Order& order) {
    orders.push_back(order);
}

void DataStorage::displayOrders() const {
    for (const auto& order : orders) {
        order.displayOrder();
    }
}

void DataStorage::startOrderPreparation() {
    std::string orderStatus = "In process";
    for (auto& order : orders) {
        if (order.getStatus() == "Paid and sent to the kitchen") {
            order.updateStatus(orderStatus);
            break;
        }
    }
}

void DataStorage::completeOrder() {
    std::string orderStatus = "Completed";
    for (auto& order : orders) {
        if (order.getStatus() == "In process") {
            order.updateStatus(orderStatus);
            break;
        }
    }
}

void DataStorage::manageMenu() {
    int choice;
    while (true) {
        std::cout << "Manage Menu:\n";
        std::cout << "1. Add Item\n";
        std::cout << "2. Remove Item\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string name, description;
            int prepTime;
            double price;
            std::vector<int> productIds;
            int productId;

            std::cout << "Enter item name: ";
            std::cin >> name;
            std::cout << "Enter preparation time: ";
            std::cin >> prepTime;
            std::cout << "Enter price: ";
            std::cin >> price;
            std::cout << "Enter description: ";
            std::cin >> description;
            std::cout << "Enter product IDs (end with -1): ";
            while (std::cin >> productId && productId != -1) {
                productIds.push_back(productId);
            }
            menu.emplace_back(name, productIds, description, prepTime, price);
            break;
        }
        case 2: {
            std::string name;
            std::cout << "Enter item name to remove: ";
            std::cin >> name;
            auto it = std::remove_if(menu.begin(), menu.end(), [&](const MenuItem& item) { return item.getName() == name; });
            if (it != menu.end()) {
                menu.erase(it);
            }
            break;
        }
        case 3:
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void DataStorage::manageProducts() {
    int choice;
    while (true) {
        std::cout << "Manage Products:\n";
        std::cout << "1. Add Product\n";
        std::cout << "2. Remove Product\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            std::string name;
            double cost;

            std::cout << "Enter product ID: ";
            std::cin >> id;
            std::cout << "Enter product name: ";
            std::cin >> name;
            std::cout << "Enter product cost: ";
            std::cin >> cost;

            products.emplace_back(id, name, cost);
            break;
        }
        case 2: {
            int id;
            std::cout << "Enter product ID to remove: ";
            std::cin >> id;
            auto it = std::remove_if(products.begin(), products.end(), [&](const Product& product) { return product.getId() == id; });
            if (it != products.end()) {
                products.erase(it);
            }
            break;
        }
        case 3:
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void DataStorage::manageEmployees() {
    int choice;
    while (true) {
        std::cout << "Manage Employees:\n";
        std::cout << "1. Add Employee\n";
        std::cout << "2. Remove Employee\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string role, login, password;
            std::cout << "Enter role (admin, cook, waiter): ";
            std::cin >> role;
            std::cout << "Enter login: ";
            std::cin >> login;
            std::cout << "Enter password: ";
            std::cin >> password;

            if (role == "admin") {
                admins.emplace_back(login, password);
            }
            else if (role == "cook") {
                cooks.emplace_back(login, password);
            }
            else if (role == "waiter") {
                waiters.emplace_back(login, password);
            }
            else {
                std::cout << "Invalid role.\n";
            }
            break;
        }
        case 2: {
            std::string role, login;
            std::cout << "Enter role (admin, cook, waiter): ";
            std::cin >> role;
            std::cout << "Enter login to remove: ";
            std::cin >> login;

            if (role == "admin") {
                auto it = std::remove_if(admins.begin(), admins.end(), [&](const auto& pair) { return pair.first == login; });
                if (it != admins.end()) {
                    admins.erase(it);
                }
            }
            else if (role == "cook") {
                auto it = std::remove_if(cooks.begin(), cooks.end(), [&](const auto& pair) { return pair.first == login; });
                if (it != cooks.end()) {
                    cooks.erase(it);
                }
            }
            else if (role == "waiter") {
                auto it = std::remove_if(waiters.begin(), waiters.end(), [&](const auto& pair) { return pair.first == login; });
                if (it != waiters.end()) {
                    waiters.erase(it);
                }
            }
            else {
                std::cout << "Invalid role.\n";
            }
            break;
        }
        case 3:
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

bool DataStorage::validateAdmin(const std::string& login, const std::string& password) const {
    for (const auto& pair : admins) {
        if (pair.first == login && pair.second == password) {
            return true;
        }
    }
    return false;
}

bool DataStorage::validateCook(const std::string& login, const std::string& password) const {
    for (const auto& pair : cooks) {
        if (pair.first == login && pair.second == password) {
            return true;
        }
    }
    return false;
}

bool DataStorage::validateWaiter(const std::string& login, const std::string& password) const {
    for (const auto& pair : waiters) {
        if (pair.first == login && pair.second == password) {
            return true;
        }
    }
    return false;
}

std::string DataStorage::getAdminName(const std::string& login) const {
    for (const auto& pair : admins) {
        if (pair.first == login) {
            return login; // Simplified: returns login as name
        }
    }
    return "";
}

std::string DataStorage::getCookName(const std::string& login) const {
    for (const auto& pair : cooks) {
        if (pair.first == login) {
            return login; // Simplified: returns login as name
        }
    }
    return "";
}

std::string DataStorage::getWaiterName(const std::string& login) const {
    for (const auto& pair : waiters) {
        if (pair.first == login) {
            return login; // Simplified: returns login as name
        }
    }
    return "";
}
