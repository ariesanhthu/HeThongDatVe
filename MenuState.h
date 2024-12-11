#pragma once
#include <iostream>
#include <string>

#include "BookingSystem.h"
#include "MenuManager.h"

using namespace std;

// Forward declaration
class MenuManager;

// Abstract State class
class MenuState
{
public:
    virtual ~MenuState() {}
    virtual void displayMenu(MenuManager& manager) = 0;
    //virtual void handleInput() = 0;
    void displayMainMenu();
};

// Login
class NotLoggedInState : public MenuState
{
public:
    void displayMenu(MenuManager& manager) override;
};
//
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


// ======= QUẢN LÝ ======= 

// MENU QUẢN LÝ CHUYẾN XE
class MenuChuyenXe : public MenuState
{
public:
    void displayMenu(MenuManager& manager) override;
};

class MenuQuanLyXe : public MenuState
{
public:
    void displayMenu(MenuManager& menuManager) override;
};

class MenuQuanLyVe : public MenuState {
public:
    void displayMenu(MenuManager& menuManager) override;
};