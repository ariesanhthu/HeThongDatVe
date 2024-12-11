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
        email(""), address(""), dateOfBirth(""), role("User") {}

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

    friend ostream& operator<<(ostream& os, const User& user) {
        os << "Username: " << user.username << '\n';
        os << "Password: " << user.password << '\n';
        os << "Ten: " << user.name << '\n';
        os << "sdt: " << user.phoneNumber << '\n';
        os << "Email: " << user.email << '\n';
        os << "Dia chi: " << user.address << '\n';
        os << "Ngay thang nam sinh: " << user.dateOfBirth << '\n';
        os << "Vai tro: " << user.role << '\n';
        return os;
    }

    friend istream& operator>>(istream& is, User& user) {
        cout << "Username: ";
        is >> user.username;
        cout << "Password: ";
        is >> user.password;
        cout << "Ho va ten: ";
        is.ignore();
        getline(is, user.name);
        cout << "sdt: ";
        is >> user.phoneNumber;
        cout << "Email: ";
        is >> user.email;
        cout << "Dia: ";
        is.ignore();
        getline(is, user.address);
        cout << "Ngay thang nam sinh (DD/MM/YYYY): ";
        is >> user.dateOfBirth;
        //cout << "Vai tro: ";
        //is >> user.role;
        return is;
    }
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

