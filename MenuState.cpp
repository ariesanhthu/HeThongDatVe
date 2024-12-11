#include "MenuState.h"

void MenuState::displayMainMenu()
{
    cout << "\n\n==== MAIN MENU ====" << endl;
    cout << "0. Thoat khoi chuong trinh\n";
    cout << "1. Tra cuu chuyen xe\n2. Xem chi tiet chuyen xe\n3. Thong tin chi tiet ve xe\n";
}

void NotLoggedInState::displayMenu(MenuManager& manager)
{
    displayMainMenu();
    cout << "==== ACCOUNT AREA ====" << endl;
    cout << "4. Dang nhap\n5. Dang ky\n";
}

void LoggedInState::displayMenu(MenuManager& manager)
{
    displayMainMenu();
    cout << "==== ACCOUNT AREA ====" << endl;
    cout << "4. Dang xuat\n";
    cout << "==== USER AREA ====" << endl;
    cout << "5. Dat ve\n6. Thanh toan\n7. Quan ly ve\n8. Quan ly tai khoan\n";
}

void AdminState::displayMenu(MenuManager& manager)
{
    cout << "==== ADMIN AREA ====" << endl;
    cout << "8. Quan ly he thong\n";
}

// ======= QUẢN LÝ ======= 

// MENU QUẢN LÝ CHUYẾN XE
void MenuChuyenXe::displayMenu(MenuManager& menuManager)
{
    QuanLyChuyenXe* quanLyChuyenXe = BookingSystem::getQuanLyChuyenXe(); // Lấy con trỏ từ hệ thống
    if (!quanLyChuyenXe)
    {
        cout << "Loi: Quan ly chuyen xe chua duoc khoi tao.\n";
        return;
    }

    int choice;
    while (true)
    {
        cout << "\n\n=== Quan Ly Chuyen Xe ===\n";
        cout << "1. Them chuyen xe moi\n";
        cout << "2. Xoa chuyen xe\n";
        cout << "3. Hien thi tat ca chuyen xe\n";
        cout << "0. Quay lai menu chinh\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            ChuyenXe* cx = new ChuyenXe();
            cout << "Nhap thong tin chuyen xe moi:\n";
            cin >> *cx;

            quanLyChuyenXe->themChuyenXe(cx);
            cout << "Them chuyen xe thanh cong!\n";
            break;
        }
        case 2:
        {
            string maChuyenXe;
            cout << "Nhap ma chuyen xe can xoa: ";
            cin >> maChuyenXe;
            if (quanLyChuyenXe->xoaChuyenXe(maChuyenXe))
            {
                cout << "Xoa chuyen xe thanh cong!\n";
            }
            else
            {
                cout << "Khong tim thay ma chuyen xe can xoa.\n";
            }
            break;
        }
        case 3:
        {
            cout << "Danh sach cac chuyen xe:\n";
            quanLyChuyenXe->hienThiTatCaChuyenXe();
            break;
        }
        case 0:
            menuManager.setState(new NotLoggedInState());
            return; // Quay lại menu chính
        default:
            cout << "Lua chon khong hop le. Vui long thu lai.\n";
        }
    }
}

void MenuQuanLyXe::displayMenu(MenuManager& menuManager)
{
    QuanLyXe* quanLyXe = BookingSystem::getQuanLyXe(); // Lấy con trỏ từ hệ thống
    if (!quanLyXe)
    {
        cout << "Loi: Quan ly xe chua duoc khoi tao.\n";
        return;
    }

    int choice;
    while (true)
    {
        cout << "\n\n=== Quan Ly Xe ===\n";
        cout << "1. Them xe moi\n";
        cout << "2. Xoa xe\n";
        cout << "3. Hien thi tat ca xe\n";
        cout << "0. Quay lai menu chinh\n";
        cout << "Nhap lua chon cua ban: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nhap khong hop le. Vui long nhap lai.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            Xe xe;
            cout << "Nhap thong tin xe moi:\n";
            cin >> xe;

            quanLyXe->themXe(xe);
            cout << "Them xe thanh cong!\n";
            break;
        }
        case 2:
        {
            string bienSoXe;
            cout << "Nhap bien so xe can xoa: ";
            cin >> bienSoXe;
            if (quanLyXe->xoaXe(bienSoXe))
            {
                cout << "Xoa xe thanh cong!\n";
            }
            else
            {
                cout << "Khong tim thay bien so xe can xoa.\n";
            }
            break;
        }
        case 3:
        {
            cout << "Danh sach cac xe:\n";
            cout << *quanLyXe << "\n"; // Dereference the pointer
            break;
        }
        case 0:
            cout << "Quay lai menu chinh.\n";
            menuManager.setState(new NotLoggedInState()); // Ensure NotLoggedInState is implemented
            return;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai.\n";
        }
    }
}


void MenuQuanLyVe::displayMenu(MenuManager& menuManager) {
    QuanLyVe* quanLyVe = BookingSystem::getQuanLyVe(); // Access QuanLyVe module
    if (!quanLyVe) {
         cout << "Loi: Quan ly ve chua duoc khoi tao.\n";
        return;
    }

    int choice;
    while (true) {
         cout << "\n\n=== Quan Ly Ve ===\n";
         cout << "1. Them ve moi\n";
         cout << "2. Xoa ve\n";
         cout << "3. Hien thi tat ca ve\n";
         cout << "0. Quay lai menu chinh\n";
         cout << "Nhap lua chon cua ban: ";

        if (!( cin >> choice)) {
             cin.clear();
             cin.ignore();
             cout << "Nhap khong hop le. Vui long nhap lai.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            Ve ve;
             cout << "Nhap thong tin ve moi:\n";
             cin >> ve;

            quanLyVe->themVe(ve);
             cout << "Them ve thanh cong!\n";
            break;
        }
        case 2: {
             string maVe;
             cout << "Nhap ma ve can xoa: ";
             cin >> maVe;
            if (quanLyVe->xoaVe(maVe)) {
                 cout << "Xoa ve thanh cong!\n";
            }
            else {
                 cout << "Khong tim thay ma ve can xoa.\n";
            }
            break;
        }
        case 3: {
             cout << "Danh sach cac ve:\n";
             cout << *quanLyVe << "\n"; // Dereference the pointer
            break;
        }
        case 0:
             cout << "Quay lai menu chinh.\n";
            menuManager.setState(new NotLoggedInState()); // Ensure NotLoggedInState is implemented
            return;
        default:
             cout << "Lua chon khong hop le. Vui long thu lai.\n";
        }
    }
}
