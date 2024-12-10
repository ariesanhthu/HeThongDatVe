#include "Service.h"
// CONSTRUCTOR & DESTRUCTOR

Service::Service() : name(""), giaTien(0) {}
Service::Service(const  string& ten, int gia) : name(ten), giaTien(gia) {}
Service::~Service() {}

// GETTER & SETTER
 string Service::getName() const {
    return name;
}

void Service::setName(const  string& ten) {
    name = ten;
}

int Service::getGiaTien() const {
    return giaTien;
}

void Service::setGiaTien(int gia) {
    giaTien = gia;
}
