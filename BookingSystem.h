#pragma once
// MENU
#include "MenuState.h"
#include "MenuManager.h"

#include <iostream>

#include "QuanLyChuyenXe.h"
#include "QuanLyXe.h"
#include "QuanLyVe.h"
#include "QuanLyTaiKhoan.h"

//#include "ThongKe.h"

#include "FactoryUser.h"
#include "FileHandle.h"


using namespace std;

// Forward declaration
class MenuManager;

class BookingSystem {
private:
    // Instance duy nhất của hệ thống
    static BookingSystem* instance;

    // Các module quản lý
    static QuanLyXe* quanLyXe;

    static QuanLyVe* quanLyVe;
    
    //static QuanLyTaiKhoan* quanLyTaiKhoan;
    QuanLyTaiKhoan* quanLyTaiKhoan;
    
    static QuanLyChuyenXe* quanLyChuyenXe;
    
    static MenuManager* currentMenu;
    //ThongKe* thongKe;

    BookingSystem();

public:

    // Xóa các hàm copy constructor và operator=
    BookingSystem(const BookingSystem&) = delete;
    BookingSystem& operator=(const BookingSystem&) = delete;

    // Phương thức tĩnh để lấy instance
    static BookingSystem* getInstance();

    static QuanLyXe* getQuanLyXe();

    static QuanLyVe* getQuanLyVe();

    static QuanLyChuyenXe* getQuanLyChuyenXe();
    
    static MenuManager* getCurrentMenu();

    static void DeleteInstance();

    //Khởi tạo và thêm dữ liệu cho chương trình
    void initData();
    
    void run();

    QuanLyTaiKhoan* getQuanLyTaiKhoan() {
        return quanLyTaiKhoan;
    }

    ~BookingSystem();
};
