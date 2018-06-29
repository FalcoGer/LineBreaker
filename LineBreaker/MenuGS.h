#pragma once
#include "GameState.h"
#include "MenuItem.h"

class MenuGS :
    public GameState
{
public:
    MenuGS(GameState::EGameState state);
    virtual ~MenuGS();

    void draw(sf::RenderWindow& window);
    void handleEvent(sf::Event evnt);
    void update(sf::Int64 deltaTime);
protected:
    std::vector<MenuItem*> items;
private:
    unsigned int selectedItem;
    sf::Int64 animationCycle;
};

