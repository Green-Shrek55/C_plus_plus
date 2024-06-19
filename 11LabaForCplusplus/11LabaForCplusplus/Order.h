#pragma once
#include <string>
#include <vector>
#include "Menu.h"

class Order {
public:
    Order(const std::string& guestName);
    void addItem(const MenuItem& item);
    void removeItem(const std::string& itemName);
    void confirmOrder();
    void updateStatus(const std::string& status);
    std::string getStatus() const;
    double getTotalPrice() const;
    void displayOrder() const;
private:
    std::string guestName;
    std::vector<MenuItem> items;
    std::string status;
    double totalPrice;
};
