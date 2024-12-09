#include "User.h"

// Getter và Setter cho Username
std::string User::getUsername() const {
    return username;
}
void User::setUsername(const std::string& value) {
    username = value;
}

// Getter và Setter cho Password
std::string User::getPassword() const {
    return password;
}
void User::setPassword(const std::string& value) {
    password = value;
}

// Getter và Setter cho Name
std::string User::getName() const {
    return name;
}
void User::setName(const std::string& value) {
    name = value;
}

// Getter và Setter cho PhoneNumber
std::string User::getPhoneNumber() const {
    return phoneNumber;
}
void User::setPhoneNumber(const std::string& value) {
    phoneNumber = value;
}

// Getter và Setter cho Email
std::string User::getEmail() const {
    return email;
}
void User::setEmail(const std::string& value) {
    email = value;
}

// Getter và Setter cho Address
std::string User::getAddress() const {
    return address;
}
void User::setAddress(const std::string& value) {
    address = value;
}

// Getter và Setter cho DateOfBirth
std::string User::getDateOfBirth() const {
    return dateOfBirth;
}
void User::setDateOfBirth(const std::string& value) {
    dateOfBirth = value;
}

// Getter và Setter cho Role
std::string User::getRole() const {
    return role;
}
void User::setRole(const std::string& value) {
    role = value;
}
