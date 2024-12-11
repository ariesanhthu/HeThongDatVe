#pragma once

#include <string>
#include <iostream>

using namespace std;

class Service {
private:
    string name;
    int giaTien;

public:
    Service();

    Service(const string& ten, int gia);

    ~Service();

    string getName() const;
    void setName(const string& ten);
    int getGiaTien() const;
    void setGiaTien(int gia);

   /* friend istream& operator>>(istream& is, Service& service);
    friend ostream& operator<<(ostream& os, const Service& service);*/
    // Overloaded << operator (output)
    friend ostream& operator<<(ostream& os, const Service& service) {
        os << "Service Name: " << service.name << ", Price: " << service.giaTien;
        return os;
    }

    // Overloaded >> operator (input)
    friend istream& operator>>(istream& is, Service& service) {
        cout << "Enter service name: ";
        is.ignore(); // Clear buffer (useful after numeric inputs)
        getline(is, service.name);
        cout << "Enter service price: ";
        is >> service.giaTien;
        return is;
    }

    // Overloaded < operator (compare by giaTien)
    bool operator<(const Service& other) const {
        return this->giaTien < other.giaTien;
    }

    // Overloaded > operator (compare by giaTien)
    bool operator>(const Service& other) const {
        return this->giaTien > other.giaTien;
    }

    // Overloaded == operator (compare by name and giaTien)
    bool operator==(const Service& other) const {
        return this->name == other.name && this->giaTien == other.giaTien;
    }

    // Overloaded != operator (inequality check)
    bool operator!=(const Service& other) const {
        return !(*this == other);
    }

    void writeToFile(ostream& out) const;
    void readFromFile(istream& in);
};

