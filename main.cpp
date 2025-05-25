#include <iostream>
#include "password_manager.h"

int main() {
    PasswordManager manager;
    int choice;
    std::string masterPassword;

    std::cout << "Enter master password: ";
    std::cin >> masterPassword;
    if (!manager.authenticate(masterPassword)) {
        std::cout << "Authentication failed!" << std::endl;
        return 1;
    }

    while (true) {
        std::cout << "\n1. Add Credential\n2. View Credentials\n3. Exit\nChoose an option: ";
        std::cin >> choice;
        if (choice == 1) {
            manager.addCredential();
        } else if (choice == 2) {
            manager.viewCredentials();
        } else {
            break;
        }
    }

    return 0;
}
