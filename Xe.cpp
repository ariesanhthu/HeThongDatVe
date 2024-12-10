#include "Xe.h"

// Constructor không tham số
//Xe::Xe() : bienSoXe(""), loaiXe(""), soChoNgoi(0), Service({}) {}

// Constructor có tham số
//Xe::Xe(const  string& bienSo, const  string& loai, int soCho, const  vector<Service>& services)
//    : bienSoXe(bienSo), loaiXe(loai), soChoNgoi(soCho), Service(services) {}

// Destructor
Xe::~Xe() {}

// Getter và Setter cho bienSoXe
 string Xe::getBienSoXe() const {
    return bienSoXe;
}
void Xe::setBienSoXe(const  string& bienSo) {
    bienSoXe = bienSo;
}

// Getter và Setter cho loaiXe
 string Xe::getLoaiXe() const {
    return loaiXe;
}
void Xe::setLoaiXe(const  string& loai) {
    loaiXe = loai;
}

// Getter và Setter cho soChoNgoi
int Xe::getSoChoNgoi() const {
    return soChoNgoi;
}
void Xe::setSoChoNgoi(int soCho) {
    soChoNgoi = soCho;
}

// Getter và Setter cho Service
vector<Service> Xe::getServices() const {
    return services;
}
void Xe::setServices(const  vector<Service>& services) {
    this->services = services;
}

