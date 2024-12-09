#include "BookingSystem.h"

int main() 
{
    BookingSystem* system = BookingSystem::getInstance();

    system->initSystem();

    system->run();

    return 0;
}
