/*
MSSV: 23127266
Họ và tên: Nguyễn Anh Thư

------BOOKING TICKET SYSTEM------

*/
#pragma once
#include "FactoryUser.h"
#include "BookingSystem.h"
#include "MenuManager.h"

int main() {
    //BookingSystem::getInstance();

    BookingSystem::getInstance()->initData();

    //system->run();
    MenuManager menuManager;

    cout << "--- Initial State (Not Logged In) ---" << endl;
    menuManager.displayMenu();

    // Switch to User State
    cout << "\n--- Switching to Admin State ---" << endl;
    menuManager.setState(new LoggedInState());
    menuManager.displayMenu();

    // Switch to Admin State
    menuManager.setState(new AdminState());
    menuManager.displayMenu();


    // HỦY ĐỐI TƯỢNG SINGLETON
    BookingSystem::DeleteInstance();

    return 0;
}
