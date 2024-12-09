#pragma once
#include <iostream>
#include "QuanLyChuyenXe.h"
#include "QuanLyXe.h"
#include "QuanLyVe.h"
#include "QuanLyTaiKhoan.h"

//#include "ThongKe.h"
//#include "FileHandler.h"

using namespace std;

class BookingSystem {
private:
    // Instance duy nhất của hệ thống
    static BookingSystem* instance;

    // Các module quản lý
    QuanLyChuyenXe* quanLyChuyenXe;
    QuanLyXe* quanLyXe;
    QuanLyVe* quanLyVe;
    QuanLyTaiKhoan* quanLyTaiKhoan;
    //ThongKe* thongKe;

    // Hàm dựng private để tránh tạo đối tượng từ bên ngoài
    BookingSystem();

public:
    // Xóa các hàm copy constructor và operator=
    BookingSystem(const BookingSystem&) = delete;
    BookingSystem& operator=(const BookingSystem&) = delete;

    // Phương thức tĩnh để lấy instance
    static BookingSystem* getInstance();

    static void DeleteInstance()
    {
        if (instance)
        {
            delete instance;
            instance = NULL;
        }
    }

    //Khởi tạo và thêm dữ liệu cho chương trình
    void initData();
    
    // Giao diện CLI
    void run();

    QuanLyTaiKhoan* getQuanLyTaiKhoan() {
        return quanLyTaiKhoan;
    }

    // Hủy tài nguyên
    ~BookingSystem();
};
