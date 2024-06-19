#pragma once
#include <vector>
#include "Menu.h"
#include "Product.h"
#include "Order.h"
#include "User.h"

class DataStorage {
public:
    DataStorage();
    void loadAllData();
    void saveAllData();
    void displayMenu() const;
    MenuItem* findMenuItem(const std::string& name);
    void addOrder(const Order& order);
    void displayOrders() const;
    void startOrderPreparation();
    void completeOrder();
    void manageMenu();
    void manageProducts();
    void manageEmployees();
    bool validateAdmin(const std::string& login, const std::string& password) const;
    bool validateCook(const std::string& login, const std::string& password) const;
    bool validateWaiter(const std::string& login, const std::string& password) const;
    std::string getAdminName(const std::string& login) const;
    std::string getCookName(const std::string& login) const;
    std::string getWaiterName(const std::string& login) const;
private:
    std::vector<MenuItem> menu;
    std::vector<Product> products;
    std::vector<Order> orders;
    std::vector<std::pair<std::string, std::string>> admins;
    std::vector<std::pair<std::string, std::string>> cooks;
    std::vector<std::pair<std::string, std::string>> waiters;
};
