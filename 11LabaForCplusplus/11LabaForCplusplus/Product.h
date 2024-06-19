#pragma once
#include <string>

class Product {
public:
    Product(int id, const std::string& name, double cost);
    int getId() const;
    std::string getName() const;
    double getCost() const;
    void displayProduct() const;
private:
    int id;
    std::string name;
    double cost;
};
