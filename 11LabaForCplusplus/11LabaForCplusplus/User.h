#pragma once
#include <string>
#include <memory>
#include "DataStorage.h"

class User {
public:
    virtual ~User() = default;
    std::string getRole() const;
    static std::shared_ptr<User> login(DataStorage& dataStorage);
protected:
    User(const std::string& role, const std::string& firstName, const std::string& lastName);
private:
    std::string role;
    std::string firstName;
    std::string lastName;
};
