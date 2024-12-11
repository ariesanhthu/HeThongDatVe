#include "QuanLyXe.h"

QuanLyXe::QuanLyXe() {}

void QuanLyXe::themXe(const Xe& xe)
{
    dsXe.push_back(xe);
}

bool QuanLyXe::xoaXe(const string& bienSoXe)
{
    for (auto it = dsXe.begin(); it != dsXe.end(); ++it)
    {
        if (it->getBienSoXe() == bienSoXe)
        {
            dsXe.erase(it);
            return true;
        }
    }
    return false;
}

bool QuanLyXe::chinhSuaXe(const string& bienSoXe, const Xe& xeMoi)
{
    for (auto& xe : dsXe)
    {
        if (xe.getBienSoXe() == bienSoXe)
        {
            xe = xeMoi;
            return true;
        }
    }
    return false;
}

ostream& operator<<(ostream& os, const QuanLyXe& qlx)
{
    os << "Danh sach xe:\n";
    for(int i = 0; i < qlx.dsXe.size(); i++)
        os << qlx.dsXe[i] << "\n";
    
    return os;
}
