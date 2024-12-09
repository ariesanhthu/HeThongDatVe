#include "BookingSystem.h"
#include "FactoryUser.h"
//==============================================
BookingSystem* BookingSystem::instance = nullptr;
//==============================================

BookingSystem::BookingSystem() 
{
    quanLyChuyenXe = nullptr;
    quanLyXe = nullptr;
    quanLyVe = nullptr;
    quanLyTaiKhoan = new QuanLyTaiKhoan();
    //thongKe = nullptr;

    cout << "He thong da duoc khoi tao thanh cong!\n";
}

// Lấy instance duy nhất của BookingSystem
BookingSystem* BookingSystem::getInstance() 
{
    if (instance == nullptr) {
        instance = new BookingSystem();
    }
    return instance;
}

// Khởi tạo và thêm data
void BookingSystem::initData()
{
    //QuanLyTaiKhoan* manager = ;

    //// Tạo người dùng
    //User* admin = FactoryUser::createUser("Admin", "admin_user", "admin_pass");
    //User* client = FactoryUser::createUser("Client", "client_user", "client_pass");

    //// Quản lý tài khoản
    //manager->addUser(admin);
    //manager->addUser(client);

    //// Hiển thị thông tin
    //admin->displayInfo();
    //client->displayInfo();
    instance->getQuanLyTaiKhoan()->addUser(FactoryUser::createUser("Admin", "admin", "admin123"));
    instance->getQuanLyTaiKhoan()->addUser(FactoryUser::createUser("Client", "client", "client123"));
    instance->getQuanLyTaiKhoan()->findUser("admin")->displayInfo();
}

//
// //Giao diện CLI
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

    cout << "He thong da duoc huy!" << endl;
}
