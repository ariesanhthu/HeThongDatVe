#pragma once
#include <string>
#include "Xe.h"

using namespace std;

class ChuyenXe {
private:
    string ID;
    string diemDi;
    string diemDen;
    string ngay; // Định dạng chuỗi, có thể thay bằng ` chrono::date` nếu cần
    string gio;  // Định dạng chuỗi, có thể thay bằng ` chrono::time`
    int giaVeCoBan;
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

    int getGiaVeCoBan() const;
    void setGiaVeCoBan(int gia);

    int getSoVeConLai() const;
    void setSoVeConLai(int soVe);

    Xe* getXe() const;
    //void setXe(const Xe& xe);
};
