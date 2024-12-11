#include "MenuManager.h"

 //Implementation of MenuManager
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

void MenuManager::displayMenu()
{
    currentState->displayMenu(*this);
}