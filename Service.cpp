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


void Service::writeToFile(std::ostream& out) const
{
    size_t nameSize = name.size();
    out.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
    out.write(name.c_str(), nameSize);
    out.write(reinterpret_cast<const char*>(&giaTien), sizeof(giaTien));
}

void Service::readFromFile(std::istream& in)
{
    size_t nameSize;
    in.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
    name.resize(nameSize);
    in.read(&name[0], nameSize);
    in.read(reinterpret_cast<char*>(&giaTien), sizeof(giaTien));
}
