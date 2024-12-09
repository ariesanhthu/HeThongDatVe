#pragma once

#include "User.h"
#include <vector>
#include <algorithm>

class QuanLyTaiKhoan {
private:
    vector<User*> users;

public:
    void addUser(User* user) {
        users.push_back(user);
    }

    User* findUser(const string& username) {
        for (auto user : users) {
            if (user->getUsername() == username) {
                return user;
            }
        }
        return nullptr;
    }

    void removeUser(const string& username) {
        users.erase(
            remove_if(users.begin(), users.end(),
                [&username](User* user) { return user->getUsername() == username; }),
            users.end());
    }


    ~QuanLyTaiKhoan() {
        for (auto user : users) {
            delete user;
        }
    }
};
