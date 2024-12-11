#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Ve.h" 

class QuanLyVe
{
private:
    vector<Ve> dsVe; // Danh sách các vé

public:
    QuanLyVe(); // Constructor

    // Thêm vé mới
    void themVe(const Ve& ve);

    // Xóa vé theo mã vé    
    bool xoaVe(const string& maVe);

    // Chỉnh sửa vé
    bool chinhSuaVe(const string& maVe, const Ve& veMoi);

    // Hiển thị danh sách tất cả các vé
    void display() const;

    // Hàm xuất danh sách vé
    friend  ostream& operator<<( ostream& os, const QuanLyVe& qlv);
};
