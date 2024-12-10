#pragma once
#include <string>
#include <vector>
#include "Service.h"

using namespace std;

class Xe {
private:
    string bienSoXe;
    string loaiXe;
    int soChoNgoi;
    vector<Service> services;

public:
    Xe();

    Xe(const  string& bienSo, const  string& loai, int soCho, const vector<Service>& services);

    ~Xe();

     string getBienSoXe() const;
    void setBienSoXe(const  string& bienSo);

     string getLoaiXe() const;
    void setLoaiXe(const  string& loai);

    int getSoChoNgoi() const;
    void setSoChoNgoi(int soCho);

    vector<Service> getServices() const;
    void setServices(const vector<Service>& services);
};

