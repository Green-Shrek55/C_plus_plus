#include "Order.h"
#include <algorithm>
#include <iostream>

Order::Order(const std::string& guestName) : guestName(guestName), status("Pending"), totalPrice(0.0) {}

void Order::addItem(const MenuItem& item) {
    items.push_back(item);
    totalPrice += item.getPrice();
}

void Order::removeItem(const std::string& itemName) {
    auto it = std::remove_if(items.begin(), items.end(), [&](const MenuItem& item) { return item.getName() == itemName; });
    if (it != items.end()) {
        totalPrice -= it->getPrice();
        items.erase(it);
    }
}

void Order::confirmOrder() {
    status = "Paid and sent to the kitchen";
}

void Order::updateStatus(const std::string& status) {
    this->status = status;
}

std::string Order::getStatus() const {
    return status;
}

double Order::getTotalPrice() const {
    return totalPrice;
}

void Order::displayOrder() const {
    std::cout << "Order for " << guestName << ":\n";
    for (const auto& item : items) {
        item.displayItem();
    }
    std::cout << "Total: " << totalPrice << "$\n";
    std::cout << "Status: " << status << "\n";
}
