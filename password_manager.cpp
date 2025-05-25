#include "password_manager.h"
#include <iostream>

bool PasswordManager::authenticate(const std::string& input) {
    return input == "admin";
}

std::string PasswordManager::encrypt(const std::string& data) {
    std::string encrypted = data;
    for (char &c : encrypted) c += 3;
    return encrypted;
}

std::string PasswordManager::decrypt(const std::string& data) {
    std::string decrypted = data;
    for (char &c : decrypted) c -= 3;
    return decrypted;
}

void PasswordManager::addCredential() {
    Credential cred;
    std::cout << "Enter site: ";
    std::cin >> cred.site;
    std::cout << "Enter username: ";
    std::cin >> cred.username;
    std::cout << "Enter password: ";
    std::cin >> cred.password;
    cred.password = encrypt(cred.password);
    credentials.push_back(cred);
}

void PasswordManager::viewCredentials() {
    for (const auto& cred : credentials) {
        std::cout << "Site: " << cred.site
                  << ", Username: " << cred.username
                  << ", Password: " << decrypt(cred.password) << std::endl;
    }
}
