/*
MSSV: 23127266
Họ và tên: Nguyễn Anh Thư

------BOOKING TICKET SYSTEM------

*/
#include "FactoryUser.h"
#include "BookingSystem.h"

int main() {
    //BookingSystem::getInstance();

    BookingSystem::getInstance()->initData();

    //system->run();
    
    // HỦY ĐỐI TƯỢNG SINGLETON
    BookingSystem::DeleteInstance();

    return 0;
}
