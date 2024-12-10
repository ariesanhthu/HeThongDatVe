#pragma once
#include <iostream>
#include <string>
using namespace std;

// Forward declaration
class MenuManager;

// Abstract State class
class MenuState
{
public:
    virtual ~MenuState() {}
    virtual void displayMenu(MenuManager& manager) = 0;
    void displayMainMenu();
};

// Login
class NotLoggedInState : public MenuState
{
public:
    void displayMenu(MenuManager& manager) override;
};

class LoggedInState : public MenuState
{
public:
    void displayMenu(MenuManager& manager) override;
};

//Account
class AdminState : public MenuState
{
public:
    void displayMenu(MenuManager& manager) override;
};
