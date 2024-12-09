#pragma once
#include <iostream>
#include <string>

using namespace std;


//// Forward declaration
//class MenuState;
//class MenuManager;

// Context Class
class MenuManager
{
private:
    MenuState* currentState;

public:
    MenuManager();
    ~MenuManager();
    void setState(MenuState* state);
    void run();
    void displayMenu();
};
