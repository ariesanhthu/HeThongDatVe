#include "BookingSystem.h"

// KHỞI TẠO CÁC BIẾN STATIC
//==============================================

BookingSystem* BookingSystem::instance = nullptr;

QuanLyChuyenXe* BookingSystem::quanLyChuyenXe = nullptr;
QuanLyXe* BookingSystem::quanLyXe = nullptr;
QuanLyVe* BookingSystem::quanLyVe = nullptr;
QuanLyTaiKhoan* BookingSystem::quanLyTaiKhoan = nullptr;

MenuManager* BookingSystem::currentMenu = nullptr;
User* BookingSystem::currentUser = nullptr;

//==============================================
// 
// KHỞI TẠO STATIC
BookingSystem::BookingSystem() 
{
    //2.1 QUẢN LÝ
    if (!quanLyChuyenXe)
        quanLyChuyenXe = new QuanLyChuyenXe();
    
    if (!quanLyXe)
        quanLyXe = new QuanLyXe();
    
    if (!quanLyXe)
        quanLyXe = new QuanLyXe();

    if (!quanLyVe)
        quanLyVe = new QuanLyVe();

    quanLyTaiKhoan = new QuanLyTaiKhoan();

    //thongKe = nullptr;
    
    //============MENU============
    if (!currentMenu)
    {
        currentMenu = new MenuManager();
        currentMenu->setState(new NotLoggedInState());
    }

    cout << "He thong da duoc khoi tao thanh cong!\n";
}

// GET các biến static
BookingSystem* BookingSystem::getInstance() 
{
    if (!instance)
    {
        instance = new BookingSystem();
    }

    return instance;
}

QuanLyChuyenXe* BookingSystem::getQuanLyChuyenXe()
{   
    return quanLyChuyenXe;
}
QuanLyTaiKhoan* BookingSystem::getQuanLyTaiKhoan()
{   
    return quanLyTaiKhoan;
}

QuanLyXe* BookingSystem::getQuanLyXe()
{   
    return quanLyXe;
}
QuanLyVe* BookingSystem::getQuanLyVe()
{   
    return quanLyVe;
}
User* BookingSystem::getCurrentUser()
{
    return currentUser;
}
//
//MenuManager* BookingSystem::getCurrentMenu()
//{
//    return currentMenu;
//}

// Khởi tạo và thêm data
void BookingSystem::initData()
{
    cout << "=========== KHOI TAO DU LIEU ==========\n";
    ////QuanLyTaiKhoan* manager = ;

    ////// Tạo người dùng
    ////User* admin = FactoryUser::createUser("Admin", "admin_user", "admin_pass");
    ////User* client = FactoryUser::createUser("Client", "client_user", "client_pass");

    ////// Quản lý tài khoản
    ////manager->addUser(admin);
    ////manager->addUser(client);

    ////// Hiển thị thông tin
    ////admin->displayInfo();
    ////client->displayInfo();
    //instance->getQuanLyTaiKhoan()->addUser(FactoryUser::createUser("Admin", "admin", "admin123"));
    //instance->getQuanLyTaiKhoan()->addUser(FactoryUser::createUser("Client", "client", "client123"));
    //instance->getQuanLyTaiKhoan()->findUser("admin")->displayInfo();
    
    
    
    
    // Dữ liệu mẫu cho Xe


    //Xe xe1("29A-12345", "Xe khach", 45);
    //Xe xe2("30B-67890", "Xe giuong nam", 50);
    //quanLyXe->themXe(xe1);
    //quanLyXe->themXe(xe2);

    // Ghi danh sách xe vào file
    // FileHandle::writeXe("dsXe.dat", { xe1, xe2 });

    // Dữ liệu mẫu cho ChuyenXe
    /*ChuyenXe* cx1 = new ChuyenXe("CX001", "Ha Noi", "Hai Phong", "2024-12-15", "08:00", 150000, 45, &xe1);
    ChuyenXe* cx2= new ChuyenXe("CX002", "Ha Noi", "Da Nang", "2024-12-16", "20:00", 500000, 50, &xe2);
    quanLyChuyenXe->themChuyenXe(cx1);
    quanLyChuyenXe->themChuyenXe(cx2);*/

    // Ghi danh sách chuyến xe vào file
    /*vector<ChuyenXe*> dschuyenxe = { cx1 , cx2 };
    FileHandle::writeChuyenXe("dsChuyenXe.dat", dschuyenxe);*/

    // Dữ liệu mẫu cho Ve
   /* Ve ve1("VE001", "Nguyen Van A", "2024-12-10", "Dat cho");
    Ve ve2("VE002", "Le Thi B", "2024-12-11", "Thanh toan");
    quanLyVe->themVe(ve1);
    quanLyVe->themVe(ve2);*/

    // Ghi danh sách vé vào file
    //FileHandle::writeVe("dsVe.dat", { ve1, ve2 });

    // Dữ liệu mẫu cho User
    //User user1("admin", "123456", "Admin", "0987654321", "admin@gmail.com", "Ha Noi", "1990-01-01", "Admin");
    //User user2("user", "password", "User", "0123456789", "user@gmail.com", "Hai Phong", "2000-01-01", "Customer");
    //User* user1 = new User("admin", "123456", "Admin", "0987654321", "admin@gmail.com", "Ha Noi", "1990-01-01", "Admin");
    //User* user2 = new User("user", "password", "User", "0123456789", "user@gmail.com", "Hai Phong", "2000-01-01", "Customer");
    //quanLyTaiKhoan->addUser(user1);
    //quanLyTaiKhoan->addUser(user2);

    // Ghi danh sách user vào file
    //FileHandle::writeUser("dsUser.dat", { user1, user2 });

    // Đọc lại dữ liệu từ file để kiểm tra
    auto dsXe = FileHandle::readXe("dsXe.dat");
    auto dsChuyenXe = FileHandle::readChuyenXe("dsChuyenXe.dat");
    auto dsVe = FileHandle::readVe("dsVe.dat");
    auto dsUser = FileHandle::readUser("dsUser.dat");

    // Thêm tài khoản vào danh sách quản lý tài khoản
    for (User it : dsUser)
    {
        quanLyTaiKhoan->addUser(new User(it));
        //cout << it << "\n";
    }

    cout << "Khoi tao du lieu thanh cong!\n";
    cout << "--------------------------------\n";

}
//
//#include "windows.h";

void BookingSystem::run()
{
    cout << "\n=== He Thong Dat Ve Xe Khach ===\n";

    if (!currentMenu)
    {
        cout << "Loi: currentMenu chua duoc khoi tao.\n";
        return;
    }

    int choice;

    while (true)
    {
        // INIT
        //Sleep(1000);
        //system("cls");

        //Check User
        if (currentUser == nullptr)
        {
            currentMenu->setState(new NotLoggedInState());
        }
        else
        {
            // ĐÃ ĐĂNG NHẬP
                currentMenu->setState(new LoggedInState());
        }
        
        
        currentMenu->displayMenu();
       

        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        if (choice == 0)
            return;

        switch (choice)
        {
        case 1:
        {
            currentMenu->setState(new MenuChuyenXe());
            break;
        }
        case 2:
        {
            currentMenu->setState(new MenuQuanLyXe());
            break;
        }
        case 3:
        {
            currentMenu->setState(new MenuQuanLyVe());
            break;
        }
        // ============== ACCOUNT ==============
        case 4:
        {
            currentMenu->setState(new MenuLogin());
            break;
        }
        // ============== ADMIN MANAGEMENT ==============
        case 9:
        {
            currentMenu->setState(new MenuQuanLy());
            break;
        }
        default:
            cout << "Lua chon khong hop le. Vui long thu lai.\n";
        }

        // SHOW MENU AFTER CHOOSE
        system("cls");
        currentMenu->displayMenu();
    }
}

// Hủy tài nguyên
BookingSystem::~BookingSystem() {
   /* delete quanLyChuyenXe;
    delete quanLyXe;
    delete quanLyVe;*/
    //delete thongKe;

    cout << "He thong da duoc huy!" << endl;
}
void BookingSystem::DeleteInstance()
{
    if (instance)
    {
        delete instance;
        instance = NULL;
    }

    if (quanLyChuyenXe)
    {
        delete quanLyChuyenXe;
        quanLyChuyenXe = NULL;
    }

    if (currentMenu)
    {
        delete currentMenu;
        currentMenu = NULL;
    }

    if (quanLyXe)
    {
        delete quanLyXe;
        quanLyXe = NULL;
    }

    if (quanLyVe)
    {
        delete quanLyVe;
        quanLyVe = NULL;
    }

    if (quanLyTaiKhoan)
    {
        delete quanLyTaiKhoan;
        quanLyTaiKhoan = NULL;
    }

    if (currentUser)
    {
        delete currentUser;
        currentUser = NULL;
    }
}