#include "ChuyenXe.h"

// CONSTRUCTOR & DESTRUCTOR

ChuyenXe::ChuyenXe()
    : ID(""), diemDi(""), diemDen(""), ngay(""), gio(""), giaVeCoBan(0), soVeConLai(0), xe() {}
ChuyenXe::ChuyenXe(const string& id, const string& diemDi, const string& diemDen,
    const string& ngay, const string& gio, int giaVe, int soVe, const Xe* xe)
    : ID(id), diemDi(diemDi), diemDen(diemDen), ngay(ngay), gio(gio),
    giaVeCoBan(giaVe), soVeConLai(soVe) {

    // tạo con trỏ mới
    this->xe = new Xe(*xe);
}
ChuyenXe::~ChuyenXe() {}

// GETTER & SETTER
string ChuyenXe::getID() const {return ID;}
void ChuyenXe::setID(const  string& id) { ID = id;}
string ChuyenXe::getDiemDi() const {return diemDi;}
void ChuyenXe::setDiemDi(const  string& diem) { diemDi = diem;}

string ChuyenXe::getDiemDen() const {return diemDen;}
void ChuyenXe::setDiemDen(const  string& diem) { diemDen = diem; }

string ChuyenXe::getNgay() const { return ngay;}
void ChuyenXe::setNgay(const  string& ngay) { this->ngay = ngay;}

string ChuyenXe::getGio() const { return gio; }
void ChuyenXe::setGio(const  string& gio) { this->gio = gio; }

int ChuyenXe::getGiaVeCoBan() const { return giaVeCoBan; }
void ChuyenXe::setGiaVeCoBan(int gia) { giaVeCoBan = gia; }

int ChuyenXe::getSoVeConLai() const { return soVeConLai;}
void ChuyenXe::setSoVeConLai(int soVe) { soVeConLai = soVe;}

Xe* ChuyenXe::getXe() const { return xe; }
//void ChuyenXe::setXe(const Xe& xe) {this->xe = xe;}
