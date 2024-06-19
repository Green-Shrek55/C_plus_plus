#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Product.h"

class MenuItem {
public:
    MenuItem(const std::string& name, const std::vector<int>& productIds, const std::string& description, int prepTime, double price);
    std::string getName() const;
    std::vector<int> getProductIds() const;
    std::string getDescription() const;
    int getPrepTime() const;
    double getPrice() const;
    void displayItem() const;
private:
    std::string name;
    std::vector<int> productIds;
    std::string description;
    int prepTime;
    double price;
};

class Menu {
public:
    void addItem(const MenuItem& item);
    void removeItem(const std::string& name);
    MenuItem* findItem(const std::string& name);
    void displayMenu() const;
    std::vector<MenuItem> getItems() const;
private:
    std::vector<MenuItem> items;
};
