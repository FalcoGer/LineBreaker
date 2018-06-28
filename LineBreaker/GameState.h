#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class GameState
{
public:
    static enum EGameState
    {
        MainMenu,
        GameRunning,
        GamePaused,
        Exit
    };

    inline GameState(EGameState state) { this->state = state; }
    inline ~GameState() {}

    // draws all objects in the current gamestate
    virtual void draw(sf::RenderWindow& window) = 0;
    // handles events
    virtual void handleEvent(sf::Event evnt) = 0;
    // updates all entities in the gamestate
    virtual void update(sf::Int64 deltaTime) = 0;

    // returns true if the game state has changed it's state
    virtual bool hasGameStateChanged() = 0;

    inline EGameState getState() { return state; }
protected:
    EGameState state;
};