#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "RenderItem.h"

#include <iostream>

using namespace std;

class GameState
    : public RenderItem
{
public:
    enum EGameState
    {
        MainMenu,
        Game,
        Exit
    };

    inline GameState(EGameState state) { this->state = state; defaultState = state; }
    virtual inline ~GameState()
    {
#if _DEBUG
        printf("GameState @ %p destroy\n", this);
#endif
    }

    // draws all objects in the current gamestate
    virtual void draw(sf::RenderWindow& window) = 0;
    // handles events
    virtual void handleEvent(sf::Event evnt) = 0;
    // updates all entities in the gamestate
    virtual void update(sf::Int64 deltaTime) = 0;

    // returns true if the game state has changed it's state
    inline bool hasGameStateChanged() { return state != defaultState; };

    inline EGameState getState() { return state; }
    inline void setState(EGameState state) { this->state = state; }
private:
    EGameState state;
    EGameState defaultState;
};