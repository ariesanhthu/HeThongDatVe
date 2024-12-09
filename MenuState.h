#pragma once
#include "MenuManager.h"
// Abstract State Class
class MenuState
{
public:
    virtual ~MenuState() {}
    virtual void displayMenu(MenuManager& manager) = 0;
};

// Concrete States

// State for Not Logged In
class NotLoggedInState : public MenuState
{
public:
    void displayMenu(MenuManager& manager) override
    {
        cout << "==== MAIN MENU ====" << endl;
        cout << "1. Tra cuu chuyen xe\n2. Xem chi tiet chuyen xe\n3. Thong tin chi tiet ve xe\n";
        cout << "==== ACCOUNT AREA ====" << endl;
        cout << "4. Dang nhap\n5. Dang ky\n";
    }
};

// State for Logged In as User
class UserState : public MenuState
{
public:
    void displayMenu(MenuManager& manager) override
    {
        cout << "==== MAIN MENU ====" << endl;
        cout << "1. Tra cuu chuyen xe\n2. Xem chi tiet chuyen xe\n3. Thong tin chi tiet ve xe\n";
        cout << "==== USER AREA ====" << endl;
        cout << "4. Dat ve\n5. Thanh toan\n6. Quan ly ve\n7. Quan ly tai khoan\n";
        cout << "==== ACCOUNT AREA ====" << endl;
        cout << "8. Dang xuat\n";
    }
};

// State for Logged In as Admin
class AdminState : public MenuState
{
public:
    void displayMenu(MenuManager& manager) override
    {
        cout << "==== MAIN MENU ====" << endl;
        cout << "1. Tra cuu chuyen xe\n2. Xem chi tiet chuyen xe\n3. Thong tin chi tiet ve xe\n";
        cout << "==== USER AREA ====" << endl;
        cout << "4. Dat ve\n5. Thanh toan\n6. Quan ly ve\n7. Quan ly tai khoan\n";
        cout << "==== ADMIN AREA ====" << endl;
        cout << "8. Quan ly he thong\n";
        cout << "==== ACCOUNT AREA ====" << endl;
        cout << "9. Dang xuat\n";
    }
};

// Implementation of MenuManager
MenuManager::MenuManager()
{
    currentState = new NotLoggedInState();
}

MenuManager::~MenuManager()
{
    delete currentState;
}

void MenuManager::setState(MenuState* state)
{
    delete currentState;
    currentState = state;
}

void MenuManager::run()
{
    while (true)
    {
        displayMenu();
        int choice;
        cout << "\nNhap lua chon: ";
        cin >> choice;
        // Logic to handle user input will go here (e.g., switching states or exiting)
    }
}

void MenuManager::displayMenu()
{
    currentState->displayMenu(*this);
}
