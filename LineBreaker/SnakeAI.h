#pragma once

#include "Snake.h"


class SnakeAI :
    public Snake
{
public:
    SnakeAI(GameBoard* gameBoard);
    ~SnakeAI();

    // Geerbt über Snake
    EDirection getControl();
};

