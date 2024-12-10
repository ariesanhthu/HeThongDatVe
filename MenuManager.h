#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "MenuState.h"

using namespace std;

// Forward declaration
class MenuState;

// MenuManager manages the current state and displays the menu
class MenuManager
{
private:
    MenuState* currentState;

public:
    MenuManager();
    ~MenuManager();

    void setState(MenuState* state);
    void displayMenu();
};

