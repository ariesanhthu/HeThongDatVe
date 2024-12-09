#include "BookingSystem.h"

// Khởi tạo con trỏ tĩnh instance là nullptr
BookingSystem* BookingSystem::instance = nullptr;

// Hàm dựng
BookingSystem::BookingSystem() {
    quanLyChuyenXe = nullptr;
    quanLyXe = nullptr;
    quanLyVe = nullptr;
    //thongKe = nullptr;
}

// Lấy instance duy nhất của BookingSystem
BookingSystem* BookingSystem::getInstance() {
    if (instance == nullptr) {
        instance = new BookingSystem();
    }
    return instance;
}

// Khởi tạo các module
void BookingSystem::initSystem() {
    quanLyChuyenXe = new QuanLyChuyenXe();
    quanLyXe = new QuanLyXe();
    quanLyVe = new QuanLyVe();
    //thongKe = new ThongKe();

    cout << "Hệ thống đã được khởi tạo thành công." << endl;
}

// Giao diện CLI
//void BookingSystem::run() {
//    cout << "=== Hệ Thống Đặt Vé Xe Khách ===" << endl;
//    int choice;
//    do {
//        cout << "1. Quản lý chuyến xe" << endl;
//        cout << "2. Quản lý xe" << endl;
//        cout << "3. Quản lý vé" << endl;
//        cout << "4. Báo cáo thống kê" << endl;
//        cout << "5. Thoát" << endl;
//        cout << "Chọn chức năng (1-5): ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            quanLyChuyenXe->manage();
//            break;
//        case 2:
//            quanLyXe->manage();
//            break;
//        case 3:
//            quanLyVe->manage();
//            break;
//        case 4:
//            thongKe->report();
//            break;
//        case 5:
//            cout << "Thoát chương trình." << endl;
//            break;
//        default:
//            cout << "Lựa chọn không hợp lệ. Vui lòng thử lại." << endl;
//            break;
//        }
//    } while (choice != 5);
//}

// Hủy tài nguyên
BookingSystem::~BookingSystem() {
    delete quanLyChuyenXe;
    delete quanLyXe;
    delete quanLyVe;
    //delete thongKe;

    cout << "Hệ thống đã được giải phóng." << endl;
}
