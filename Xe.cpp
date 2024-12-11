#include "Xe.h"

// Constructor không tham số
Xe::Xe() : bienSoXe(""), loaiXe(""), soChoNgoi(10) {}

 //Constructor có tham số
Xe::Xe(const  string& bienSo, const  string& loai, int soCho)
    : bienSoXe(bienSo), loaiXe(loai), soChoNgoi(soCho){}

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

istream& operator>>(istream& is, Xe& xe) {
    cout << "Nhap bien so xe: ";
    is.ignore(); // Clear buffer to avoid skipping input
    getline(is, xe.bienSoXe);

    cout << "Nhap loai xe: ";
    getline(is, xe.loaiXe);

    cout << "Nhap so cho ngoi: ";
    is >> xe.soChoNgoi;

    // Input for services
    int serviceCount;
    cout << "Nhap so luong dich vu cua xe: ";
    is >> serviceCount;
    is.ignore(); // Clear buffer after reading an integer

    xe.services.clear();
    for (int i = 0; i < serviceCount; ++i) {
        Service service;
        cout << "Nhap thong tin dich vu thu " << (i + 1) << ":\n";
        is >> service;
        xe.services.push_back(service);
    }

    return is;
}

// Overloaded << operator for output
ostream& operator<<(ostream& os, const Xe& xe) {
    os << "Bien so xe: " << xe.bienSoXe << "\n";
    os << "Loai xe: " << xe.loaiXe << "\n";
    os << "So cho ngoi: " << xe.soChoNgoi << "\n";
    os << "Danh sach dich vu:\n";

    if (xe.services.empty()) {
        os << "Khong co dich vu nao.\n";
    }
    else {
        for (size_t i = 0; i < xe.services.size(); ++i) {
            os << "  Dich vu " << (i + 1) << ": " << xe.services[i] << "\n";
        }
    }

    return os;
}

void Xe::writeToFile(std::ostream& out) const
{
    size_t bienSoSize = bienSoXe.size();
    size_t loaiXeSize = loaiXe.size();

    out.write(reinterpret_cast<const char*>(&bienSoSize), sizeof(bienSoSize));
    out.write(bienSoXe.c_str(), bienSoSize);
    out.write(reinterpret_cast<const char*>(&loaiXeSize), sizeof(loaiXeSize));
    out.write(loaiXe.c_str(), loaiXeSize);
    out.write(reinterpret_cast<const char*>(&soChoNgoi), sizeof(soChoNgoi));

    size_t serviceCount = services.size();
    out.write(reinterpret_cast<const char*>(&serviceCount), sizeof(serviceCount));
    for (const auto& service : services)
    {
        service.writeToFile(out);
    }
}

void Xe::readFromFile(std::istream& in)
{
    size_t bienSoSize, loaiXeSize;

    in.read(reinterpret_cast<char*>(&bienSoSize), sizeof(bienSoSize));
    bienSoXe.resize(bienSoSize);
    in.read(&bienSoXe[0], bienSoSize);

    in.read(reinterpret_cast<char*>(&loaiXeSize), sizeof(loaiXeSize));
    loaiXe.resize(loaiXeSize);
    in.read(&loaiXe[0], loaiXeSize);

    in.read(reinterpret_cast<char*>(&soChoNgoi), sizeof(soChoNgoi));

    size_t serviceCount;
    in.read(reinterpret_cast<char*>(&serviceCount), sizeof(serviceCount));
    services.resize(serviceCount);
    for (auto& service : services)
    {
        service.readFromFile(in);
    }
}
