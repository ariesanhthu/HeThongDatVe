#include "MenuState.h"
#include "MenuManager.h"

void MenuState::displayMainMenu()
{
    cout << "==== MAIN MENU ====" << endl;
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
