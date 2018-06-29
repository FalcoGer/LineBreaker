#pragma once
#include "GameState.h"
#include "MenuItem.h"

#define _USE_MATH_DEFINES
#include <math.h>

class MenuGS :
    public GameState
{
public:
    MenuGS(GameState::EGameState state);
    ~MenuGS();

    void draw(sf::RenderWindow& window);
    void handleEvent(sf::Event evnt);
    void update(sf::Int64 deltaTime);

    virtual bool hasGameStateChanged() = 0;
protected:
    std::vector<MenuItem*> items;
private:
    unsigned int selectedItem;
    sf::Int64 animationCycle;
};

