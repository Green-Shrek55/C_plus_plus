#include "Menu.h"
#include <algorithm>

MenuItem::MenuItem(const std::string& name, const std::vector<int>& productIds, const std::string& description, int prepTime, double price)
    : name(name), productIds(productIds), description(description), prepTime(prepTime), price(price) {}

std::string MenuItem::getName() const { return name; }
std::vector<int> MenuItem::getProductIds() const { return productIds; }
std::string MenuItem::getDescription() const { return description; }
int MenuItem::getPrepTime() const { return prepTime; }
double MenuItem::getPrice() const { return price; }

void MenuItem::displayItem() const {
    std::cout << "Name: " << name << ", Description: " << description << ", Preparation Time: " << prepTime << " min, Price: " << price << "$\n";
}

void Menu::addItem(const MenuItem& item) {
    items.push_back(item);
}

void Menu::removeItem(const std::string& name) {
    items.erase(std::remove_if(items.begin(), items.end(), [&](const MenuItem& item) { return item.getName() == name; }), items.end());
}

MenuItem* Menu::findItem(const std::string& name) {
    for (auto& item : items) {
        if (item.getName() == name) {
            return &item;
        }
    }
    return nullptr;
}

void Menu::displayMenu() const {
    for (const auto& item : items) {
        item.displayItem();
    }
}

std::vector<MenuItem> Menu::getItems() const {
    return items;
}
