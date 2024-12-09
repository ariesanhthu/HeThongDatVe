#pragma once
#include "User.h"

class FactoryUser {
public:
    // truyền user*
    static User* createUser(const string& role, const string& username, const string& password) {
        if (role == "Client") {
            return new Client(username, password);
        }
        else if (role == "Admin") {
            return new Admin(username, password);
        }
        return nullptr;
    }
};