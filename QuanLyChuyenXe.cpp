#include "QuanLyChuyenXe.h"

// Thêm chuyến xe mới
void QuanLyChuyenXe::themChuyenXe(ChuyenXe* chuyenXe)
{
    dsChuyenXe.push_back(chuyenXe);
    cout << "Da them chuyen xe thanh cong!\n";
}

// Chỉnh sửa thông tin chuyến xe
bool QuanLyChuyenXe::chinhSuaChuyenXe(string id, string ngayGioMoi, double giaVeMoi)
{
    for (ChuyenXe* cx : dsChuyenXe)
    {
        if (cx->getID() == id)
        {
            cx->setNgay(ngayGioMoi);
            cx->setGiaVeCoBan(giaVeMoi);
            cout << "Thong tin chuyen xe da duoc cap nhat!\n";
            return true;
        }
    }
    cout << "Khong tim thay chuyen xe!\n";
    return false;
}

// Xóa chuyến xe
bool QuanLyChuyenXe::xoaChuyenXe(string id)
{
    for (auto it = dsChuyenXe.begin(); it != dsChuyenXe.end(); ++it)
    {
        if ((*it)->getID() == id)
        {
            delete* it;
            dsChuyenXe.erase(it);
            cout << "Da xoa chuyen xe thanh cong!\n";
            return true;
        }
    }
    cout << "Khong tim thay chuyen xe!\n";
    return false;
}

// Hiển thị tất cả chuyến xe
void QuanLyChuyenXe::hienThiTatCaChuyenXe()
{
    if (dsChuyenXe.empty())
    {
        cout << "Khong co chuyen xe nao!\n";
    }
    else
    {
        for (ChuyenXe* cx : dsChuyenXe)
        {
            cout << *cx;
            cout << "---------------------------------\n";
        }
    }
}

// Destructor
QuanLyChuyenXe::~QuanLyChuyenXe()
{
    for (ChuyenXe* cx : dsChuyenXe)
    {
        delete cx;
    }
}
