#include "Utils.h"

namespace Utils {
    bool isValidLogin(const std::string& login) {
        return !login.empty();
    }

    bool isValidPassword(const std::string& password) {
        return password.length() >= 6;
    }
}
