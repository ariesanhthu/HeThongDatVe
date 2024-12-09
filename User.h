#pragma once

#include <string>
#include <iostream>
using namespace std;

class User {
protected:
    string username;
    string password;
    string name;
    string phoneNumber;
    string email;
    string address;
    string dateOfBirth;
    string role;

public:
    User(const string& username, const string& password, const string& role)
        : username(username), password(password), role(role) {}

    virtual void displayInfo() {
        cout << "Username: " << username << endl;
        cout << "Role: " << role << endl;
    }

    virtual ~User() {}

    // Getter và Setter cho Username
    std::string getUsername() const;
    void setUsername(const std::string& value);

    // Getter và Setter cho Password
    std::string getPassword() const;
    void setPassword(const std::string& value);

    // Getter và Setter cho Name
    std::string getName() const;
    void setName(const std::string& value);

    // Getter và Setter cho PhoneNumber
    std::string getPhoneNumber() const;
    void setPhoneNumber(const std::string& value);

    // Getter và Setter cho Email
    std::string getEmail() const;
    void setEmail(const std::string& value);

    // Getter và Setter cho Address
    std::string getAddress() const;
    void setAddress(const std::string& value);

    // Getter và Setter cho DateOfBirth
    std::string getDateOfBirth() const;
    void setDateOfBirth(const std::string& value);

    // Getter và Setter cho Role
    std::string getRole() const;
    void setRole(const std::string& value);
};

class Client : public User {
public:
    Client(const string& username, const string& password)
        : User(username, password, "Client") {}

    void displayInfo() override {
        cout << "Client Info: " << endl;
        User::displayInfo();
    }
};

class Admin : public User {
public:
    Admin(const string& username, const string& password)
        : User(username, password, "Admin") {}

    void displayInfo() override {
        cout << "Admin Info: " << endl;
        User::displayInfo();
    }
};

