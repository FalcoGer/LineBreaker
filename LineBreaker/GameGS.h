#pragma once
#include "GameState.h"
#include "GameBoard.h"

#include <iostream>

using namespace std;

class GameGS :
    public GameState
{
public:
    GameGS();
    ~GameGS();

    void draw(sf::RenderWindow & window);
    void handleEvent(sf::Event evnt);
    void update(sf::Int64 deltaTime);

private:
    GameBoard* gameBoard;
};

