#include "Ve.h"

istream& operator>>(istream& is, Ve& ve)
{
    cout << "Nhap ma ve: ";
    is >> ve.maVe;
    cout << "Nhap ten khach hang: ";
    is >> ve.tenKhachHang;
    cout << "Nhap ngay dat: ";
    is >> ve.ngayDat;
    cout << "Nhap trang thai ve: ";
    is >> ve.trangThai;

    return is;
}

ostream& operator<<(ostream& os, const Ve& ve)
{
    os << "- Ma ve: " << ve.maVe << "\n";
    os << "- Ten khach hang : " << ve.tenKhachHang << "\n";
    os << "- Ngay dat: " << ve.ngayDat << "\n";
    os << "- Trang thai: " << ve.trangThai << "\n";

    return os;
}

void Ve::readFromFile(ifstream& inFile)
{
    getline(inFile, maVe, '\0');
    getline(inFile, tenKhachHang, '\0');
    getline(inFile, ngayDat, '\0');
    getline(inFile, trangThai, '\0');
}

void Ve::writeToFile(ofstream& outFile) const
{
    outFile.write(maVe.c_str(), maVe.size() + 1);
    outFile.write(tenKhachHang.c_str(), tenKhachHang.size() + 1);
    outFile.write(ngayDat.c_str(), ngayDat.size() + 1);
    outFile.write(trangThai.c_str(), trangThai.size() + 1);
}
