#pragma once
#include <string>
#include "Xe.h"
#include <iostream>

#include <fstream>

using namespace std;

class ChuyenXe {
private:
    string ID;
    string diemDi;
    string diemDen;
    string ngay; 
    string gio;  
    double giaVeCoBan;

    // đặt vé thành công thông báo để thay đổi số vé còn lại
    // khởi tạo bằng số chỗ ngồi của xe
    int soVeConLai;
    Xe* xe; 

public:
    ChuyenXe();
    ChuyenXe(const string& id, const  string& diemDi, const  string& diemDen,
        const  string& ngay, const  string& gio, int giaVe, int soVe, const Xe* xe);
    ~ChuyenXe();

    string getID() const;
    void setID(const string& id);

    string getDiemDi() const;
    void setDiemDi(const  string& diem);

    string getDiemDen() const;
    void setDiemDen(const  string& diem);

    string getNgay() const;
    void setNgay(const  string& ngay);

    string getGio() const;
    void setGio(const  string& gio);

    double getGiaVeCoBan() const;
    void setGiaVeCoBan(double gia);

    int getSoVeConLai() const;
    void setSoVeConLai(int soVe);

    Xe* getXe() const;
    //void setXe(const Xe& xe);

     // Overloading << và >>
    friend ostream& operator<<(ostream& os, const ChuyenXe& cx);
    friend istream& operator>>(istream& is, ChuyenXe& cx);

    //file

    void readFromFile(ifstream& inFile);
    void writeToFile(ofstream& outFile) const;
};
