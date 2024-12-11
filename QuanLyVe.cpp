#include "QuanLyVe.h"

QuanLyVe::QuanLyVe() {}

void QuanLyVe::themVe(const Ve& ve)
{
    dsVe.push_back(ve);
}

bool QuanLyVe::xoaVe(const string& maVe)
{
    for (auto it = dsVe.begin(); it != dsVe.end(); ++it)
    {
        if (it->getMaVe() == maVe)
        {
            dsVe.erase(it);
            return true;
        }
    }
    return false;
}

bool QuanLyVe::chinhSuaVe(const string& maVe, const Ve& veMoi)
{
    for (auto& ve : dsVe)
    {
        if (ve.getMaVe() == maVe)
        {
            ve = veMoi;
            return true;
        }
    }
    return false;
}

void QuanLyVe::display() const
{
     cout << "Danh sach cac ve:\n";
    for (const auto& ve : dsVe)
    {
         cout << ve << "\n";
    }
}

 ostream& operator<<( ostream& os, const QuanLyVe& qlv)
{
    os << "Danh sach ve:\n";
    for (const auto& ve : qlv.dsVe)
    {
        os << ve << "\n";
    }

    return os;
}
