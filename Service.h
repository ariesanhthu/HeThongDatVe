#pragma once

#include <string>

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
};

