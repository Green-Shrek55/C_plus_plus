#include <iostream>
#include "Menu.h"
#include "Order.h"
#include "User.h"
#include "Admin.h"
#include "Cook.h"
#include "Waiter.h"
#include "Guest.h"
#include "DataStorage.h"

int main() {
    DataStorage dataStorage;
    dataStorage.loadAllData();

    std::shared_ptr<User> user = User::login(dataStorage);
    if (!user) {
        std::cout << "Ошибка авторизации!\n";
        return 1;
    }

    if (user->getRole() == "admin") {
        std::static_pointer_cast<Admin>(user)->manageSystem(dataStorage);
    }
    else if (user->getRole() == "cook") {
        std::static_pointer_cast<Cook>(user)->manageOrders(dataStorage);
    }
    else if (user->getRole() == "waiter") {
        std::static_pointer_cast<Waiter>(user)->serveOrders(dataStorage);
    }
    else if (user->getRole() == "guest") {
        std::static_pointer_cast<Guest>(user)->makeOrder(dataStorage);
    }

    dataStorage.saveAllData();
    return 0;
}
