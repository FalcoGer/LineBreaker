#pragma once

#include "MenuGS.h"
#include "MenuItem.h"
#include "ActionCoutExample.h"
#include "ActionChangeGameState.h"
#include <iostream>
#include <vector>

using namespace std;

class MainMenuGS :
    public MenuGS
{
public:
    MainMenuGS(sf::Font* font);
    ~MainMenuGS();

    inline bool hasGameStateChanged() { return getState() != GameState::EGameState::MainMenu; }
};

