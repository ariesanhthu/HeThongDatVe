#pragma once
#include <iostream>
#include <string>

#include <fstream>

using namespace std;

class Ve
{
private:
    string maVe;
    string tenKhachHang;
    string ngayDat;
    string trangThai; //"Đã đặt", "Đã hủy", "Cho thanh toan"

public:
    Ve() : maVe("0"), tenKhachHang("unknow"), ngayDat("01/01/0000"), trangThai("0") {};

    Ve(const string& maVe, const string& tenKhachHang,
        const string& ngayDat, const string& trangThai)
        : maVe(maVe), tenKhachHang(tenKhachHang), ngayDat(ngayDat), trangThai(trangThai) {}

    // Getter
    string getMaVe() const { return maVe; }
    string getTenKhachHang() const { return tenKhachHang; }
    string getNgayDat() const { return ngayDat; }
    string getTrangThai() const { return trangThai; }

    // Setter
    void setTrangThai(const string& trangThaiMoi) { trangThai = trangThaiMoi; }
    void setTenKhachHang(const string& tenMoi) { tenKhachHang = tenMoi; }

    // In thông tin vé
    friend  ostream& operator<<(ostream& os, const Ve& ve);

    friend  istream& operator>>(istream& is, Ve& ve);

    void readFromFile(ifstream& inFile);
    void writeToFile(ofstream& outFile) const;
};
