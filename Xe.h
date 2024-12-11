#pragma once
#include <string>
#include <vector>
#include "Service.h"
#include <iostream>

#include <fstream>

using namespace std;

class Xe {
private:
    string bienSoXe;
    string loaiXe;
    int soChoNgoi;
    vector<Service> services;

public:
    Xe();

    Xe(const  string& bienSo, const  string& loai, int soCho);

    ~Xe();

     string getBienSoXe() const;
    void setBienSoXe(const  string& bienSo);

     string getLoaiXe() const;
    void setLoaiXe(const  string& loai);

    int getSoChoNgoi() const;
    void setSoChoNgoi(int soCho);

    vector<Service> getServices() const;
    void setServices(const vector<Service>& services);

    void addService(const Service& service) { services.push_back(service); }

    void writeToFile(std::ostream& out) const;
    void readFromFile(std::istream& in);


    friend istream& operator>>(istream& is, Xe& xe);
    friend ostream& operator<<(ostream& os, const Xe& xe);
};

