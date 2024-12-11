#include "FileHandle.h"

//=========================================================================================
// READ FILE
//=========================================================================================

std::vector<ChuyenXe> FileHandle::readChuyenXe(const std::string& filename)
{
    std::vector<ChuyenXe> danhSachChuyenXe;
    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile)
    {
        std::cerr << "Khong the mo file: " << filename << "\n";
        return danhSachChuyenXe;
    }

    while (inFile.peek() != EOF)
    {
        ChuyenXe chuyenXe;
        chuyenXe.readFromFile(inFile);
        danhSachChuyenXe.push_back(chuyenXe);
    }

    inFile.close();
    return danhSachChuyenXe;
}

std::vector<Ve> FileHandle::readVe(const std::string& filename)
{
    std::vector<Ve> danhSachVe;
    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile)
    {
        std::cerr << "Khong the mo file: " << filename << "\n";
        return danhSachVe;
    }

    while (inFile.peek() != EOF)
    {
        Ve ve;
        ve.readFromFile(inFile);
        danhSachVe.push_back(ve);
    }

    inFile.close();
    return danhSachVe;
}

std::vector<Xe> FileHandle::readXe(const std::string& filename)
{
    std::vector<Xe> danhSachXe;
    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile)
    {
        std::cerr << "Khong the mo file: " << filename << "\n";
        return danhSachXe;
    }

    while (inFile.peek() != EOF)
    {
        Xe xe;
        xe.readFromFile(inFile);
        danhSachXe.push_back(xe);
    }

    inFile.close();
    return danhSachXe;
}

std::vector<User> FileHandle::readUser(const std::string& filename)
{
    std::vector<User> danhSachUser;
    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile)
    {
        std::cerr << "Khong the mo file: " << filename << "\n";
        return danhSachUser;
    }

    while (inFile.peek() != EOF)
    {
        User user;
        user.readFromFile(inFile);
        danhSachUser.push_back(user);
    }

    inFile.close();
    return danhSachUser;
}

//=========================================================================================
// WRITE FILE
//=========================================================================================


// Ghi danh sách ChuyenXe vào file
void FileHandle::writeChuyenXe(const string& filename, const vector<ChuyenXe*>& data)
{
    ofstream outFile(filename, ios::binary);
    if (!outFile)
    {
        cerr << "Khong the mo file " << filename << " de ghi.\n";
        return;
    }

    for (const auto& chuyenXe : data)
    {
        if (chuyenXe) // Check for null pointers
        {
            chuyenXe->writeToFile(outFile);
        }
    }

    outFile.close();
    cout << "Ghi danh sach ChuyenXe vao file thanh cong.\n";
}


// Ghi danh sách Ve vào file
void FileHandle::writeVe(const string& filename, const vector<Ve>& data)
{
    ofstream outFile(filename, ios::binary);
    if (!outFile)
    {
        cerr << "Khong the mo file " << filename << " de ghi.\n";
        return;
    }

    for (const auto& ve : data)
    {
        ve.writeToFile(outFile);
    }

    outFile.close();
    cout << "Ghi danh sach Ve vao file thanh cong.\n";
}

// Ghi danh sách Xe vào file
void FileHandle::writeXe(const string& filename, const vector<Xe>& data)
{
    ofstream outFile(filename, ios::binary);
    if (!outFile)
    {
        cerr << "Khong the mo file " << filename << " de ghi.\n";
        return;
    }

    for (const auto& xe : data)
    {
        xe.writeToFile(outFile);
    }

    outFile.close();
    cout << "Ghi danh sach Xe vao file thanh cong.\n";
}

// Ghi danh sách User vào file
void FileHandle::writeUser(const string& filename, const vector<User*>& data)
{
    ofstream outFile(filename, ios::binary);
    if (!outFile)
    {
        cerr << "Khong the mo file " << filename << " de ghi.\n";
        return;
    }

    for (const auto& user : data)
    {
        user->writeToFile(outFile);
    }

    outFile.close();
    cout << "Ghi danh sach User vao file thanh cong.\n";
}
