#pragma once
#include "ChuyenXe.h"
#include <vector>

using namespace std;

class QuanLyChuyenXe
{
private:
    vector<ChuyenXe*> dsChuyenXe;

public:
    void themChuyenXe(ChuyenXe* chuyenXe);
    bool chinhSuaChuyenXe(string id, string ngay, double gio);
    bool xoaChuyenXe(string id);
    void hienThiTatCaChuyenXe();
    
    // Destructor
    ~QuanLyChuyenXe();
};
