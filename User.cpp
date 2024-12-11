#include "User.h"

// Getter và Setter cho Username
 string User::getUsername() const {
    return username;
}
void User::setUsername(const  string& value) {
    username = value;
}

// Getter và Setter cho Password
 string User::getPassword() const {
    return password;
}
void User::setPassword(const  string& value) {
    password = value;
}

// Getter và Setter cho Name
 string User::getName() const {
    return name;
}
void User::setName(const  string& value) {
    name = value;
}

// Getter và Setter cho PhoneNumber
 string User::getPhoneNumber() const {
    return phoneNumber;
}
void User::setPhoneNumber(const  string& value) {
    phoneNumber = value;
}

// Getter và Setter cho Email
 string User::getEmail() const {
    return email;
}
void User::setEmail(const  string& value) {
    email = value;
}

// Getter và Setter cho Address
 string User::getAddress() const {
    return address;
}
void User::setAddress(const  string& value) {
    address = value;
}

// Getter và Setter cho DateOfBirth
 string User::getDateOfBirth() const {
    return dateOfBirth;
}
void User::setDateOfBirth(const  string& value) {
    dateOfBirth = value;
}

// Getter và Setter cho Role
 string User::getRole() const {
    return role;
}
void User::setRole(const  string& value) {
    role = value;
}

void User::readFromFile(ifstream& inFile)
{
    // Đọc từng thuộc tính dưới dạng chuỗi
    getline(inFile, username, '\0');
    getline(inFile, password, '\0');
    getline(inFile, name, '\0');
    getline(inFile, phoneNumber, '\0');
    getline(inFile, email, '\0');
    getline(inFile, address, '\0');
    getline(inFile, dateOfBirth, '\0');
    getline(inFile, role, '\0');
}

void User::writeToFile(std::ofstream& outFile) const
{
    // Ghi từng thuộc tính dưới dạng chuỗi
    outFile.write(username.c_str(), username.size() + 1);
    outFile.write(password.c_str(), password.size() + 1);
    outFile.write(name.c_str(), name.size() + 1);
    outFile.write(phoneNumber.c_str(), phoneNumber.size() + 1);
    outFile.write(email.c_str(), email.size() + 1);
    outFile.write(address.c_str(), address.size() + 1);
    outFile.write(dateOfBirth.c_str(), dateOfBirth.size() + 1);
    outFile.write(role.c_str(), role.size() + 1);
}