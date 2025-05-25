#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H

#include <vector>
#include <string>

struct Credential {
    std::string site;
    std::string username;
    std::string password;
};

class PasswordManager {
private:
    std::vector<Credential> credentials;
    std::string encryptionKey = "secret";

public:
    bool authenticate(const std::string& input);
    void addCredential();
    void viewCredentials();
    std::string encrypt(const std::string& data);
    std::string decrypt(const std::string& data);
};

#endif
