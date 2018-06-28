#pragma once

#include "GameState.h"
#include "MenuItem.h"
#include <iostream>
#include <vector>

using namespace std;

class MainMenuGS :
    public GameState
{
public:
    MainMenuGS(sf::Font* font);
    ~MainMenuGS();

    void draw(sf::RenderWindow& window);
    void handleEvent(sf::Event evnt);
    void update(sf::Int64 deltaTime);

    inline bool hasGameStateChanged() { return state != GameState::EGameState::MainMenu; }
private:
    std::vector<MenuItem*> items;
    unsigned int selectedItem;
};

