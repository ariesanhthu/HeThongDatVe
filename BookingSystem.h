#pragma once
#ifndef BOOKING_SYSTEM_H
#define BOOKING_SYSTEM_H

#include <iostream>
#include "QuanLyChuyenXe.h"
#include "QuanLyXe.h"
#include "QuanLyVe.h"
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
    //ThongKe* thongKe;

    // Hàm dựng private để tránh tạo đối tượng từ bên ngoài
    BookingSystem();

public:
    // Xóa các hàm copy constructor và operator=
    BookingSystem(const BookingSystem&) = delete;
    BookingSystem& operator=(const BookingSystem&) = delete;

    // Phương thức tĩnh để lấy instance
    static BookingSystem* getInstance();

    // Phương thức khởi tạo các module
    void initSystem();

    // Giao diện CLI
    void run();

    // Hủy tài nguyên
    ~BookingSystem();
};

#endif // BOOKING_SYSTEM_H
