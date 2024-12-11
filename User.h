#pragma once

#include <string>
#include <iostream>

#include <fstream>

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
    User()
        : username(""), password(""), name(""), phoneNumber(""),
        email(""), address(""), dateOfBirth(""), role("") {}

    User(const string& username, const string& password, const string& role)
        : username(username), password(password), role(role) {}

    User(const string& username, const string& password, const string& name,
        const string& phoneNumber, const string& email, const string& address,
        const string& dateOfBirth, const string& role)
        : username(username), password(password), name(name), phoneNumber(phoneNumber),
        email(email), address(address), dateOfBirth(dateOfBirth), role(role)
    {
    }
    virtual void displayInfo() {
        cout << "Username: " << username << endl;
        cout << "Role: " << role << endl;
    }

    virtual ~User() {}

    // Getter và Setter cho Username
     string getUsername() const;
    void setUsername(const  string& value);

    // Getter và Setter cho Password
     string getPassword() const;
    void setPassword(const  string& value);

    // Getter và Setter cho Name
     string getName() const;
    void setName(const  string& value);

    // Getter và Setter cho PhoneNumber
     string getPhoneNumber() const;
    void setPhoneNumber(const  string& value);

    // Getter và Setter cho Email
     string getEmail() const;
    void setEmail(const  string& value);

    // Getter và Setter cho Address
     string getAddress() const;
    void setAddress(const  string& value);

    // Getter và Setter cho DateOfBirth
     string getDateOfBirth() const;
    void setDateOfBirth(const  string& value);

    // Getter và Setter cho Role
     string getRole() const;
    void setRole(const  string& value);

    // Đọc và ghi file
    void readFromFile(ifstream& inFile);
    void writeToFile(ofstream& outFile) const;
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

