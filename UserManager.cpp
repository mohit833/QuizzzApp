#include "UserManager.h"
#include <fstream>
#include <iostream>

void UserManager::registerUser(const std::string& username, const std::string& password) {
    std::ofstream file("user.txt", std::ios::app);
    file << username << " " << password << "\n";
    std::cout << "Registration successful.\n";
}

bool UserManager::authenticateUser(const std::string& username, const std::string& password) {
    std::ifstream file("user.txt");
    std::string uname, pwd;
    while (file >> uname >> pwd) {
        if (uname == username && pwd == password) {
            return true;
        }
    }
    return false;
}