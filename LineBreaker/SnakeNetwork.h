#pragma once
#include "Snake.h"

class SnakeNetwork
    : public Snake
{
public:
    SnakeNetwork(GameBoard* gameBoard);
    ~SnakeNetwork();

    EDirection getControl();
};

