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
    BookingSystem::getInstance()->run();
    
    // HỦY ĐỐI TƯỢNG SINGLETON
    BookingSystem::DeleteInstance();

    return 0;
}
