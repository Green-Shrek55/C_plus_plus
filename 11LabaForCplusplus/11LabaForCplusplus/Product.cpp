#include "Product.h"
#include <iostream>

Product::Product(int id, const std::string& name, double cost) : id(id), name(name), cost(cost) {}

int Product::getId() const { return id; }
std::string Product::getName() const { return name; }
double Product::getCost() const { return cost; }

void Product::displayProduct() const {
    std::cout << "ID: " << id << ", Name: " << name << ", Cost: " << cost << "$\n";
}
