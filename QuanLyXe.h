#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Xe.h"

class QuanLyXe
{
private:
    vector<Xe> dsXe;

public:
    QuanLyXe();

    void themXe(const Xe& xe);
    bool xoaXe(const string& bienSoXe);
    bool chinhSuaXe(const string& bienSoXe, const Xe& xeMoi);

    friend ostream& operator<<(ostream& os, const QuanLyXe& qlx);
};