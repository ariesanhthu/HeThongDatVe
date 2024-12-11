#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "ChuyenXe.h"
#include "Ve.h"
#include "Xe.h"
#include "User.h"

using namespace std;

class FileHandle
{
public:
    static vector<ChuyenXe> readChuyenXe(const string& filename);
    static vector<Ve> readVe(const string& filename);
    static vector<Xe> readXe(const string& filename);
    static vector<User> readUser(const string& filename);


    // Ghi dữ liệu vào file
    static void writeChuyenXe(const string& filename, const vector<ChuyenXe*>& data);
    static void writeVe(const string& filename, const vector<Ve>& data);
    static void writeXe(const string& filename, const vector<Xe>& data);
    static void writeUser(const string& filename, const vector<User*>& data);
};

